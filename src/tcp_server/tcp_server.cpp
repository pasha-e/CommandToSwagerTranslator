#include "tcp_server.h"
#include <thread>
#include <iostream>
#include <memory>
#include <mutex>
#include <qtcpsocket.h>
#include <QDataStream>
namespace
{
    uint32_t server_port = 41285;
	std::once_flag init_flag;
	std::string TAG = "Tcp server. ";
}
namespace skif {
namespace adapters {
namespace azr
{
	namespace tcp
	{
		//������, ������������ � �������
		TcpClient::TcpClient(bool need_echo, QTcpSocket* socket)
			: QObject(socket)
			, m_pack_size(0)
			, m_st(stage::read_header)
			, m_socket(socket)
			, m_need_echo(need_echo)
			, m_handle(socket->socketDescriptor())
		{
			
			connect(socket, &QTcpSocket::readyRead, this, &TcpClient::read);
			connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
				[this](QAbstractSocket::SocketError err) {				
			});
			connect(socket, &QTcpSocket::disconnected, [this]() {
				emit disconnected(m_handle);
			});
		}
		void TcpClient::read()
		{
			if (m_st == stage::read_header)
				readHeader();
			else if (m_st == stage::read_data)
				readData();
		}
		void TcpClient::readHeader()
		{
			if (m_socket->bytesAvailable() >= sizeof(m_pack_size))
			{
				auto data = m_socket->read(sizeof(m_pack_size));
				QDataStream stream(data);
				stream.setByteOrder(QDataStream::LittleEndian);
				stream >> m_pack_size;                
				m_st = stage::read_data;
				if (m_socket->bytesAvailable() > 0)
					read();
			}
		}

		void TcpClient::readData()
		{
			if (m_socket->bytesAvailable() >= m_pack_size)
			{
				auto data = m_socket->read(m_pack_size);
				emit dataReady(data, m_handle);
				m_st = stage::read_header;
				if (m_need_echo)
					write(data);
				if (m_socket->bytesAvailable() > 0)
					read();
				
			}
		}

		qint64 TcpClient::write(QByteArray data)
		{			
			QByteArray package;
			QDataStream stream(&package, QIODevice::WriteOnly);
			stream.setByteOrder(QDataStream::LittleEndian);
			stream << static_cast<uint32_t>(data.size());
			package.append(data);
			return m_socket->write(package, package.size());
		}

		//---------------------------------------
		TcpServer::TcpServer(init_params params, QObject* parent)
			: m_params(std::move(params))
			, QObject(parent)
			, m_server(new QTcpServer(this))
		{
			m_clients = {};
			connect(m_server, &QTcpServer::newConnection, this, &TcpServer::handle_accept);
			m_server->listen(QHostAddress::Any, server_port);            
		}
        void TcpServer::start()
        {
        }
		TcpServer::~TcpServer()
		{
		}

		qint64 TcpServer::sendData(const QByteArray data, client_handle_t h)
		{
			if (m_clients.empty())
				return -1;

			if (h == 0)
			{
				quint64 len = 0;
				for (auto client : m_clients)
					len+=client.second->write(data);
				return len;
			}

            if(m_clients.find(h) != m_clients.end())
                return m_clients[h]->write(data);
                            
			return -1;
		}

		void TcpServer::handle_accept()
		{			
			if (m_server->hasPendingConnections())
			{
				QTcpSocket* socket = m_server->nextPendingConnection();
				m_clients[socket->socketDescriptor()] = new TcpClient(m_params.need_echo,socket);
				emit clientConnected(socket->socketDescriptor());
				connect(m_clients[socket->socketDescriptor()], &TcpClient::dataReady, this, &TcpServer::dataRecived);
				connect(m_clients[socket->socketDescriptor()], &TcpClient::disconnected, [this](client_handle_t h) {
					emit clientDisconnected(h);
					m_clients.erase(h);
				});
				connect(m_clients[socket->socketDescriptor()], &TcpClient::error, this, &TcpServer::error);
			}
		}
		bool TcpServer::isConnect(client_handle_t h)
		{
			if (m_clients.empty())
				return false;
			if (h == 0)
			{
				for (auto client : m_clients)
					if (client.second->isConnect())
						return true;
				return false;
			}

			if (m_clients.find(h) == m_clients.end())
				return false;
			else
				return m_clients[h]->isConnect();

		}
}//namespace tcp
}//namespace mniti
}
}
