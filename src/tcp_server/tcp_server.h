#ifndef webacs_TcpServer__h
#define webacs_TcpServer__h

#include <functional>
#include <vector>
#include <queue>
#include "decl.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <map>

namespace skif {
namespace adapters {
namespace azr
{
	namespace tcp
	{
		using client_handle_t = qintptr;

		class TcpClient : public QObject
		{
			Q_OBJECT
		public:
			enum class stage
			{
				read_header,
				read_data
			};
		public:
			TcpClient(bool need_echo, QTcpSocket* socket);
			~TcpClient() = default;
			qint64 write(QByteArray data);
			bool isConnect() { return m_socket->state() == QAbstractSocket::SocketState::ConnectedState; };

		signals:
			void dataReady(QByteArray data, client_handle_t h);
			void disconnected(client_handle_t h);
			void error(QString error);

		private slots:
			void read();

		private:            
			client_handle_t m_handle;
			bool m_need_echo;
			stage m_st;
			quint32 m_pack_size;
			QTcpSocket* m_socket;
			void readHeader();
			void readData();
		};

		class SKIFADAPTERS_MNITI_TCP_SERVER_DECL TcpServer : public QObject
		{
			Q_OBJECT
		public:

			struct init_params
			{
				bool need_echo = false;
				init_params(bool ne = false) 
				: need_echo(){}
			};

		public:
			TcpServer(init_params params, QObject* parent);
                        void start();
			~TcpServer();
			
			bool isConnect(client_handle_t h);

		private:            

			using message = std::pair<std::vector<char>, int>;
			init_params m_params;
			QTcpServer* m_server;
			std::map<client_handle_t, TcpClient*> m_clients;

		public slots:
			qint64 sendData(const QByteArray data, client_handle_t h);

		private slots:

			void handle_accept();

		signals:
			void clientConnected(client_handle_t h);
			void clientDisconnected(client_handle_t h);
			void error(QString error);
			void dataRecived(QByteArray data, client_handle_t h);
		};
	}
}
}
}

#endif
