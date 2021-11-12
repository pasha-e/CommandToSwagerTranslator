#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <tcp_server.h>
#include <ru.ascin.kcs.api.qt5cpp/OAIAssemblyApi.h>
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 

using namespace skif::adapters::azr;

using namespace OpenAPI;

//void OnClientConnected(tcp::client_handle_t h);

void testGetByGuidFunction1();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
  /*         
   
    tcp::TcpServer* testServer = new tcp::TcpServer(new tcp::TcpServer::init_params(false), nullptr);
      
    QObject::connect(testServer, &tcp::TcpServer::clientConnected, OnClientConnected);
   
    std::cout<<"Server is running"<<std::endl;*/

    testGetByGuidFunction1();
    
    return a.exec();
}

void testGetByGuidFunction1()
{
     OAIAssemblyApi apiInstance;
     apiInstance.setTimeOut(10000);
             
      QEventLoop loop;
      /*
      QObject::connect(&apiInstance, &OAIAssemblyApi::assembly_getByGuidSignal, [&]() {
          loop.quit();
      });
      QObject::connect(&apiInstance, &OAIAssemblyApi::assembly_getByGuidSignalE, [&](QNetworkReply::NetworkError, QString error_str) {
          qDebug() << "Error happened while issuing request : " << error_str;          
          loop.quit();
      });
      */

        //[Guid("E67F6EED-573C-41F8-82AA-BC12D1C51BD8")]
      QString guid = "E67F6EED-573C-41F8-82AA-BC12D1C51BD8"; 
      apiInstance.assembly_getByGuid(guid);
      QTimer::singleShot(5000, &loop, &QEventLoop::quit);
      loop.exec();
  }

/*
void OnClientConnected(tcp::client_handle_t h)
{
    std::cout<<"Client connected "<<h<<std::endl;
}*/