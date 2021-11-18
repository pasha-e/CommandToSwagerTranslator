#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <../tcp_server/tcp_server.h>
//#include <../client/OAIAssemblyApi.h>
#include "client/OAIAssemblyApi.h"
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 

#include "client/OAIDefaultApi.h"


void OnGetByGuidSygnal(OpenAPI::OAIAssembly summary)
{
    std::cout << "getByGuidSignal responsed " << summary.asJson().toStdString() << std::endl;
}

void OnGetAuthTokenSygnal(OpenAPI::OAIInline_response_200 summary)
{
    std::cout << "postOauthToken responsed " << summary.asJson().toStdString() << std::endl;
}

void testGetByGuidFunction1()
{
    OpenAPI::OAIAssemblyApi apiInstance;
    apiInstance.setTimeOut(10000);

    
    apiInstance.setNewServer("kcs.seabis.ru", QUrl("https://kcs.seabis.ru"),"No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;
    
    QObject::connect(&apiInstance, &OpenAPI::OAIAssemblyApi::assembly_getByGuidSignal, OnGetByGuidSygnal);
	/*
    QObject::connect(&apiInstance, &OpenAPI::OAIAssemblyApi::assembly_getByGuidSignalE, [&](QNetworkReply::NetworkError, QString error_str) {
        qDebug() << "Error happened while issuing request : " << error_str;
        loop.quit();
    });*/
    
	//[Guid("E67F6EED-573C-41F8-82AA-BC12D1C51BD8")]
    QString guid = "E67F6EED-573C-41F8-82AA-BC12D1C51BD8";
    apiInstance.assembly_getByGuid(guid);
    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
}
void testGetAuthTokenFunction()
{
    OpenAPI::OAIDefaultApi apiInstance;
    apiInstance.setTimeOut(10000);

	apiInstance.setNewServerForAllOperations( QUrl("https://kcs.seabis.ru"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;

    QObject::connect(&apiInstance, &OpenAPI::OAIDefaultApi::postOauthTokenSignal, OnGetAuthTokenSygnal);

    apiInstance.postOauthToken("","");

    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
	
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

  //  return a.exec();
    std::cout << "app started" << std::endl;
    //testGetByGuidFunction1();
    testGetAuthTokenFunction();

    return a.exec();
}

