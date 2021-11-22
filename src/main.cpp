#include <QCoreApplication>
#include <iostream>
#include <conio.h>
//#include <../tcp_server/tcp_server.h>
//#include <../client/OAIAssemblyApi.h>
#include "client/OAIAssemblyApi.h"
#include "client/OAIAuthApi.h"
#include "client/OAIWorkspaceApi.h"
#include "client/OAIWorkspace.h"
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 

using  OpenAPI::OAIWorkspace;

QString accessToken;
QString refreshToken;

void OnGetByGuidSignal(OpenAPI::OAIAssembly summary)
{
    std::cout << "getByGuidSignal responsed " << summary.asJson().toStdString() << std::endl;
}

void OnGetListWorkspaceSignal(QList<OAIWorkspace> summary)
{
    std::cout << "GetListWorkspaceSignal responsed " << summary.at(0).asJson().toStdString() << std::endl;
}

void OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary)
{
    QJsonObject jsonResponse = summary.asJsonObject();
    accessToken = jsonResponse.value("access_token").toString();
    refreshToken = jsonResponse.value("refresh_token").toString();

    std::cout << "access_token: " << accessToken.toStdString() << std::endl;
    std::cout << "refresh_token: " << refreshToken.toStdString() << std::endl;
    std::cout << "postOauthToken responsed:  " << summary.asJson().toStdString() << std::endl;
}


void OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
{
    std::cout << "postOauthTokenErr responsed:  " << error_type<< "  "<< error_type << std::endl;
    std::cout << summary.asJson().toStdString() << std::endl;
	
}

void testGetAuthTokenFunction()
{
    OpenAPI::OAIAuthApi apiInstance;
    apiInstance.setTimeOut(10000);	

	//http://localhost:3000/api/v1/rest
	apiInstance.setNewServerForAllOperations( QUrl("http://kcs.seabis.ru:8080"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;

    QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::oauth_postOauthTokenSignal, OnGetAuthTokenSignal);

 //   QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::postOauthTokenSignalE, OnGetAuthTokenSignalError);

    const QString contentTypeParams("application/x-www-form-urlencoded");
    const QString authParams ("Basic Y2xpZW50OnNlY3JldA==");
    const QString grantTypeParams("password");
    QString usernameParams("rest_user");
    QString passwordParams("rest_user");
	
    apiInstance.oauth_postOauthToken(contentTypeParams, authParams, grantTypeParams,usernameParams,passwordParams);

    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
	
}

void testGetWorkspaceListFunction()
{
    OpenAPI::OAIWorkspaceApi apiInstance;

    apiInstance.setTimeOut(10000);
    apiInstance.setNewServer("kcs.seabis.ru", QUrl("https://kcs.seabis.ru"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
    apiInstance.setBearerToken(accessToken);

    QEventLoop loop;

    QObject::connect(&apiInstance, &OpenAPI::OAIWorkspaceApi::workspace_getListWorkspace, OnGetListWorkspaceSignal);
    /*
    QObject::connect(&apiInstance, &OpenAPI::OAIAssemblyApi::assembly_getByGuidSignalE, [&](QNetworkReply::NetworkError, QString error_str) {
        qDebug() << "Error happened while issuing request : " << error_str;
        loop.quit();
    });*/

    //[Guid("E67F6EED-573C-41F8-82AA-BC12D1C51BD8")]
    QString guid = "E67F6EED-573C-41F8-82AA-BC12D1C51BD8";
    OpenAPI::OptionalParam<QString> emptyParam;
    apiInstance.workspace_getListWorkspace("projectId", emptyParam, emptyParam, emptyParam, emptyParam);
    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "app started" << std::endl;
  //  initServerConfig();
  //  std::cout << "init server config done" << std::endl;
    //testGetByGuidFunction1();
    testGetAuthTokenFunction();
    std::cout << "testGetAuthTokenFunction called" << std::endl;

    testGetWorkspaceListFunction();
    std::cout << "testGetWorkspaceListFunction called" << std::endl;
    
    return a.exec();
}
