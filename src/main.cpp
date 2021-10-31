#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include "tcp_server/tcp_server.h"
#include <QtCore>

using namespace skif::adapters::azr;

void OnClientConnected(tcp::client_handle_t h);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
           
   
    tcp::TcpServer* testServer = new tcp::TcpServer(new tcp::TcpServer::init_params(false), nullptr);
      
    QObject::connect(testServer, &tcp::TcpServer::clientConnected, OnClientConnected);
   
    std::cout<<"Server is running"<<std::endl;
    
    return a.exec();
}


void OnClientConnected(tcp::client_handle_t h)
{
    std::cout<<"Client connected "<<h<<std::endl;
}