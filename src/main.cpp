#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <../tcp_server/tcp_server.h>
//#include <../client/OAIAssemblyApi.h>
#include "client/OAIAssemblyApi.h"
#include "client/OAIAuthApi.h"
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 

#include "client/OAIDefaultApi.h"


void OnGetByGuidSignal(OpenAPI::OAIAssembly summary)
{
    std::cout << "getByGuidSignal responsed " << summary.asJson().toStdString() << std::endl;
}

void OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary)
{
    std::cout << "postOauthToken responsed  " << summary.asJson().toStdString() << std::endl;
}


void OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
{
    std::cout << "postOauthTokenErr responsed:  " << error_type<< "  "<< error_type << std::endl;
    std::cout << summary.asJson().toStdString() << std::endl;
	
}


void testGetByGuidFunction1()
{
    OpenAPI::OAIAssemblyApi apiInstance;
	
    apiInstance.setTimeOut(10000);

    
    apiInstance.setNewServer("kcs.seabis.ru", QUrl("https://kcs.seabis.ru"),"No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;
    
    QObject::connect(&apiInstance, &OpenAPI::OAIAssemblyApi::assembly_getByGuidSignal, OnGetByGuidSignal);
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
    OpenAPI::OAIAuthApi apiInstance;
    apiInstance.setTimeOut(10000);	

	//http://localhost:3000/api/v1/rest
	apiInstance.setNewServerForAllOperations( QUrl("http://kcs.seabis.ru:8080"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;

    QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::postOauthTokenSignal, OnGetAuthTokenSignal);

    QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::postOauthTokenSignalE, OnGetAuthTokenSignalError);

    
    //передаем пустые объекты в метод из-за некоректной работы генератора, параметры будут установлены напрямую в headers
    OpenAPI::OptionalParam<QString> authParams;
    OpenAPI::OptionalParam<QString> contentTypeParams ;

    OpenAPI::OptionalParam<QString> grantTypeParams("password");
    OpenAPI::OptionalParam<QString> usernameParams("rest_user");
    OpenAPI::OptionalParam<QString> passwordParams("rest_user");

    apiInstance.addHeaders("Authorization", "Basic Y2xpZW50OnNlY3JldA==");
    apiInstance.addHeaders("Content-Type", "application/x-www-form-urlencoded");
	
    apiInstance.postOauthToken(contentTypeParams, authParams, grantTypeParams,usernameParams,passwordParams);

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
