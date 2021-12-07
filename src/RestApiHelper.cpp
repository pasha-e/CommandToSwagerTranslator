#include <iostream>
#include <conio.h>
#include <QtCore>

#include <QTimer>
#include <QEventLoop> 

#include "client/OAIAssemblyApi.h"
#include "client/OAIAuthApi.h"
#include "client/OAIWorkspaceApi.h"
#include "client/OAIWorkspace.h"
#include "client/OAIFilesApi.h"

#include "RestApiHelper.h"

namespace OpenApiHelper
{

	RestApiHelper::RestApiHelper()
	{
		_contentTypeParams = QString::fromStdString("application/x-www-form-urlencoded");
		_authParams = QString::fromStdString("Basic Y2xpZW50OnNlY3JldA==");
		_grantTypeParams = QString::fromStdString("password");

		_kcsUrl = QString::fromStdString("https://kcs.seabis.ru");

		_usernameParams = QString::fromStdString("rest_user");
		_passwordParams = QString::fromStdString("rest_user");


		CheckCacheDir();
	}

	RestApiHelper::~RestApiHelper()
	{
	}

	/// <summary>
		/// создание директории для кэша файлов
		/// </summary>
	void RestApiHelper::CheckCacheDir()
	{
		_fileCacheDir = QDir::currentPath() + QDir::separator() + "cache";
		QDir dir;
		if (!dir.exists(_fileCacheDir))
			dir.mkpath(_fileCacheDir);
	}

	void RestApiHelper::GetAuthToken()
	{
		OpenAPI::OAIAuthApi apiInstance;

		apiInstance.setTimeOut(10000);
		apiInstance.setNewServerForAllOperations(QUrl(_kcsUrl), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());

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

		apiInstance.oauth_postOauthToken(_contentTypeParams, _authParams, _grantTypeParams, _usernameParams, _passwordParams);

		QTimer::singleShot(5000, &loop, &QEventLoop::quit);
		loop.exec();
	}

	void RestApiHelper::GetWorkspaceList()
	{
		OpenAPI::OAIWorkspaceApi apiInstance;

		apiInstance.setTimeOut(10000);
		apiInstance.setNewServerForAllOperations(QUrl(_kcsUrl + "/api/v1/rest"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
		apiInstance.setBearerToken(_accessToken);

		QEventLoop loop;


		QObject::connect(&apiInstance, &OpenAPI::OAIWorkspaceApi::workspace_getListWorkspaceSignal, [&](QList<OpenAPI::OAIWorkspace> summary)
			{
				OnGetListWorkspaceSignal(summary);
				loop.quit();
			});

		QObject::connect(&apiInstance, &OpenAPI::OAIWorkspaceApi::workspace_getListWorkspaceSignalE, [&](QList<OpenAPI::OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str)
			{
				OnGetListWorkspaceSignalError(summary, error_type, error_str);

				loop.quit();
			});



		OpenAPI::OptionalParam<QString> emptyParam;

		apiInstance.workspace_getListWorkspace("projectId");

		QTimer::singleShot(5000, &loop, &QEventLoop::quit);
		loop.exec();
	}

	void RestApiHelper::GetFile(std::string fileRef)
	{
		OpenAPI::OAIFilesApi    apiInstance;
		apiInstance.setTimeOut(10000);
		apiInstance.setNewServerForAllOperations(QUrl(_kcsUrl + "/api/v1/rest"), "No description provided", QMap<QString, OpenAPI::OAIServerVariable>());
		apiInstance.setBearerToken(_accessToken);

		apiInstance.setWorkingDirectory(_fileCacheDir);

		QEventLoop loop;

		QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::files_getFilesSignal, [&](OpenAPI::OAIHttpFileElement summary)
			{
				OnGetFilesSignal(summary);
				loop.quit();
			});
		/*
		QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::files_getFilesSignalFull, [&](OpenAPI::OAIHttpRequestWorker* worker, OpenAPI::OAIHttpFileElement summary)
			{
				OnGetFilesSignalFull(worker, summary);
				loop.quit();
			});
		  */
		QObject::connect(&apiInstance, &OpenAPI::OAIFilesApi::files_getFilesSignalE, [&](OpenAPI::OAIHttpFileElement summary, QNetworkReply::NetworkError error_type, QString error_str)
			{
				OnGetFilesSignalError(summary, error_type, error_str);

				loop.quit();
			});


		OpenAPI::OptionalParam<QString> nameParam;
		bool attachmentTypeParam(true);

		std::cout << "Request file: " << fileRef << std::endl;

		apiInstance.files_getFiles(QString::fromStdString(fileRef), attachmentTypeParam, nameParam);

		QTimer::singleShot(5000, &loop, &QEventLoop::quit);
		loop.exec();
	}

	QList<QString> RestApiHelper::CurrentFilesList()
	{
		return _filesRefList;
	}

	void RestApiHelper::OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary)
	{
		QJsonObject jsonResponse = summary.asJsonObject();
		_accessToken = jsonResponse.value("access_token").toString();
		_refreshToken = jsonResponse.value("refresh_token").toString();
		std::cout << "postOauthToken responsed:  " << std::endl;
		std::cout << "access_token: " << _accessToken.toStdString() << std::endl;
		std::cout << "refresh_token: " << _refreshToken.toStdString() << std::endl;
		std::cout << summary.asJson().toStdString() << std::endl;
	}

	void RestApiHelper::OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str)
	{
		std::cout << "postOauthTokenErr responsed:  " << error_type << "  " << error_str.toStdString() << std::endl;
		std::cout << summary.asJson().toStdString() << std::endl;
	}



	void RestApiHelper::OnGetListWorkspaceSignal(QList<OpenAPI::OAIWorkspace> summary)
	{
		std::cout << "GetListWorkspaceSignal responsed " << std::endl;

		foreach(OpenAPI::OAIWorkspace value, summary)
		{
			QJsonObject jsonResponse = value.asJsonObject();

			_filesRefList.append(jsonResponse.value("fileRef").toString());

			std::cout << value.asJson().toStdString() << std::endl;

		}

		std::cout << "Files list:" << std::endl;
		foreach(QString value, _filesRefList)
		{
			std::cout << value.toStdString() << std::endl;
		}
		std::cout << std::endl;
	}

	void  RestApiHelper::OnGetListWorkspaceSignalError(QList<OpenAPI::OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str)
	{
		std::cout << "OnGetListWorkspaceSignalError responsed:  " << error_type << "  " << error_str.toStdString() << std::endl;

		foreach(OpenAPI::OAIWorkspace value, summary)
		{
			std::cout << value.asJson().toStdString() << std::endl;
		}
	}


	void RestApiHelper::OnGetFilesSignal(OpenAPI::OAIHttpFileElement summary)
	{
		std::cout << "getFilesSignal responsed" << std::endl;
		std::cout << "File lenght: " << summary.asByteArray().length() << std::endl;
		std::cout << "File name: " << summary.request_filename.toStdString() << std::endl;

		QString path("FileDownloadDirectory/");
		QDir dir;

		if (!dir.exists(path))
			dir.mkpath(path);

		bool result = false;

		QFile fileToSave(path + summary.request_filename.remove('\"'));

		result = fileToSave.open(QIODevice::WriteOnly);

		QByteArray byteArr = summary.asByteArray();
		fileToSave.write(byteArr);
		fileToSave.close();

		if (!result) {
			std::cout << "Error creating file " << summary.request_filename.toStdString() << std::endl << std::endl;
		}
		else
		{
			std::cout << "File " << summary.request_filename.toStdString() << "successfully created at " << path.toStdString() << std::endl << std::endl;
		}
	}

	void RestApiHelper::OnGetFilesSignalFull(OpenAPI::OAIHttpRequestWorker* worker, OpenAPI::OAIHttpFileElement summary)
	{
		std::cout << "getFilesSignal responsed" << std::endl;
		QString msg = QString("Success! %1 bytes").arg(worker->response.length());
		std::cout << msg.toStdString() << std::endl;
	}

	void RestApiHelper::OnGetFilesSignalError(OpenAPI::OAIHttpFileElement summary, QNetworkReply::NetworkError error_type, QString error_str)
	{
		std::cout << "getFilesSignal responsed with error:  " << error_type << std::endl << error_str.toStdString() << std::endl;
	}
}