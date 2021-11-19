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
    std::cout << "postOauthToken responsed  " << summary.asJson().toStdString() << std::endl;
}


void OnGetAuthTokenSygnalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
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
    //apiInstance.setUsername("client");
    //apiInstance.setPassword("secret");
	

	//http://localhost:3000/api/v1/rest
	apiInstance.setNewServerForAllOperations( QUrl("https://kcs.seabis.ru/api/v1/"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;

    QObject::connect(&apiInstance, &OpenAPI::OAIDefaultApi::postOauthTokenSignal, OnGetAuthTokenSygnal);

    QObject::connect(&apiInstance, &OpenAPI::OAIDefaultApi::postOauthTokenSignalE, OnGetAuthTokenSygnalError);

    //apiInstance.postOauthToken("Content-Type: application/x-www-form-urlencoded","Authorization: Basic client:secret");

    OpenAPI::OptionalParam<OpenAPI::OAIInline_object> inlineObject;
    inlineObject.m_Value.setUsername("rest_user");
    inlineObject.m_Value.setPassword("rest_user");
    inlineObject.m_Value.setGrantType("password");
	
    apiInstance.postOauthToken(" ", " ", inlineObject);

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


