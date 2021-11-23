#include <QCoreApplication>
#include <iostream>
#include <conio.h>
//#include <../tcp_server/tcp_server.h>
//#include <../client/OAIAssemblyApi.h>
#include "client/OAIAssemblyApi.h"
#include "client/OAIAuthApi.h"
#include "client/OAIWorkspaceApi.h"
#include "client/OAIWorkspace.h"
#include "client/OAIFilesApi.h"
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 


using  OpenAPI::OAIWorkspace;

QString _accessToken;
QString _refreshToken;

QList<QString> filesRefList;

void OnGetByGuidSignal(OpenAPI::OAIAssembly summary);

void OnGetListWorkspaceSignal(QList<OAIWorkspace> summary);
void OnGetListWorkspaceSignalError(QList<OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str);

void OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary);
void OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str);

void OnGetFilesSignal();
void OnGetFilesSignalFull(OpenAPI::OAIHttpRequestWorker* worker);
void OnGetFilesSignalError(QNetworkReply::NetworkError error_type, QString error_str);

void testGetAuthTokenFunction();
void testGetWorkspaceListFunction();
void testGetFilesFunction();


int main(int argc, char *argv[])
{
     QCoreApplication a(argc, argv);    
    	
    std::cout << "app started" << std::endl;

    std::cout << "testGetAuthTokenFunction call" << std::endl;
    testGetAuthTokenFunction();
    

    std::cout << "testGetWorkspaceListFunction call" << std::endl;
    testGetWorkspaceListFunction();
    
    std::cout << "testGetFilesFunction call" << std::endl;
    testGetFilesFunction();
    
    
    return a.exec();
}


void testGetAuthTokenFunction()
{
    OpenAPI::OAIAuthApi apiInstance;
    
    apiInstance.setTimeOut(10000);
    apiInstance.setNewServerForAllOperations(QUrl("http://kcs.seabis.ru:8080"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

    QEventLoop loop;
   
    QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::oauth_postOauthTokenSignal, [&](OpenAPI::OAIInline_response_200 summary)
    {
            OnGetAuthTokenSignal(summary);
            loop.quit();
    });

    QObject::connect(&apiInstance, &OpenAPI::OAIAuthApi::oauth_postOauthTokenSignalE, [&](OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
    {
            OnGetAuthTokenSignalError(summary, error_type, error_str);
            loop.quit();
    });

    
    const QString contentTypeParams("application/x-www-form-urlencoded");
    const QString authParams("Basic Y2xpZW50OnNlY3JldA==");
    const QString grantTypeParams("password");
    QString usernameParams("rest_user");
    QString passwordParams("rest_user");

    apiInstance.oauth_postOauthToken(contentTypeParams, authParams, grantTypeParams, usernameParams, passwordParams);

    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();        
}

void testGetWorkspaceListFunction()
{
    OpenAPI::OAIWorkspaceApi apiInstance;

    apiInstance.setTimeOut(10000);
    // apiInstance.setNewServerForAllOperations(QUrl("https://kcs.seabis.ru/api/v1/rest"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
    apiInstance.setNewServerForAllOperations(QUrl("http://kcs.seabis.ru:8080/rest"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
    apiInstance.setBearerToken(_accessToken);
 
    QEventLoop loop;

   
	QObject::connect(&apiInstance, &OpenAPI::OAIWorkspaceApi::workspace_getListWorkspaceSignal, [&](QList<OAIWorkspace> summary)
	{
            OnGetListWorkspaceSignal(summary);
            loop.quit();
	});
	   
    QObject::connect(&apiInstance, &OpenAPI::OAIWorkspaceApi::workspace_getListWorkspaceSignalE, [&](QList<OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str)
    {
            OnGetListWorkspaceSignalError(summary, error_type, error_str); 
    	
            loop.quit();
    });

	
  
    OpenAPI::OptionalParam<QString> emptyParam;
		
    apiInstance.workspace_getListWorkspace("projectId", emptyParam, emptyParam, emptyParam, emptyParam);

	QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();    
}

void testGetFilesFunction()
{
    OpenAPI::OAIFilesApi    apiInstance;
    apiInstance.setTimeOut(10000);    
    apiInstance.setNewServerForAllOperations(QUrl("http://kcs.seabis.ru:8080/rest"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
    apiInstance.setBearerToken(_accessToken);

    QEventLoop loop;

    /*QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::getFilesSignalFull, [&](OpenAPI::OAIHttpRequestWorker* worker)
        {
            OnGetFilesSignalFull(worker);
            loop.quit();
        });
    */
    QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::getFilesSignalFull, [&]()
        {
            OnGetFilesSignal();
            loop.quit();
        });

    QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::getFilesSignalE, [&](QNetworkReply::NetworkError error_type, QString error_str)
        {
            OnGetFilesSignalError(error_type, error_str);

            loop.quit();
        });

    
    OpenAPI::OptionalParam<QString> nameParam;
    QString fileRef = filesRefList[0];

    apiInstance.getFiles(fileRef);// , nameParam);

    QTimer::singleShot(5000, &loop, &QEventLoop::quit);
    loop.exec();
}

//-----------------------------------------------------------------------------------------------------------

void OnGetByGuidSignal(OpenAPI::OAIAssembly summary)
{
    std::cout << "getByGuidSignal responsed " << summary.asJson().toStdString() << std::endl;
}

void OnGetListWorkspaceSignal(QList<OAIWorkspace> summary)
{
    std::cout << "GetListWorkspaceSignal responsed "<< std::endl;    

    foreach(OAIWorkspace value, summary)
    {
        QJsonObject jsonResponse = value.asJsonObject();

        filesRefList.append(jsonResponse.value("fileRef").toString()) ;

        std::cout << value.asJson().toStdString() << std::endl;
    }    
}

void  OnGetListWorkspaceSignalError(QList<OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str)
{
    std::cout << "OnGetListWorkspaceSignalError responsed:  " << error_type << "  " << error_str.toStdString() << std::endl;

    foreach(OAIWorkspace value, summary)
    {
        std::cout << value.asJson().toStdString() << std::endl;
    }
}


void OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary)
{
    QJsonObject jsonResponse = summary.asJsonObject();
    _accessToken = jsonResponse.value("access_token").toString();
    _refreshToken = jsonResponse.value("refresh_token").toString();
    std::cout << "postOauthToken responsed:  " << std::endl;
    std::cout << "access_token: " << _accessToken.toStdString() << std::endl;
    std::cout << "refresh_token: " << _refreshToken.toStdString() << std::endl;
    std::cout << summary.asJson().toStdString() << std::endl;    
}

void OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
{
    std::cout << "postOauthTokenErr responsed:  " << error_type << "  " << error_str.toStdString() << std::endl;
    std::cout << summary.asJson().toStdString() << std::endl;    
}


void OnGetFilesSignal()
{
    std::cout << "getFilesSignal responsed"<< std::endl;    
}

void OnGetFilesSignalFull(OpenAPI::OAIHttpRequestWorker* worker)
{
    std::cout << "getFilesSignal responsed" << std::endl;
}

void OnGetFilesSignalError(QNetworkReply::NetworkError error_type, QString error_str)
{
    std::cout << "getFilesSignal responsed with error:  " << error_type << std::endl << error_str.toStdString() << std::endl;    
}