#include <QtCore>

#include "client/OAIAssemblyApi.h"
#include "client/OAIAuthApi.h"
#include "client/OAIWorkspaceApi.h"
#include "client/OAIWorkspace.h"
#include "client/OAIFilesApi.h"

namespace OpenApiHelper
{
	class RestApiHelper
	{
	public:
		RestApiHelper();
		~RestApiHelper();

		QList<QString> CurrentFilesList();

		void GetAuthToken();

		void GetWorkspaceList();

		void GetFile(std::string fileRef);

	private:

		QString _accessToken;
		QString _refreshToken;

		QString _contentTypeParams;
		QString _authParams;
		QString _grantTypeParams;

		QString _kcsUrl;

		QString _usernameParams; //��� ������������
		QString _passwordParams; //������ ������������

		QList<QString> _filesRefList;

		QString _fileCacheDir;

		/// <summary>
		/// �������� ���������� ��� ���� ������
		/// </summary>
		void CheckCacheDir();

		void OnGetAuthTokenSignal(OpenAPI::OAIInline_response_200 summary);
		void OnGetAuthTokenSignalError(OpenAPI::OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str);

		void OnGetListWorkspaceSignal(QList<OpenAPI::OAIWorkspace> summary);
		void OnGetListWorkspaceSignalError(QList<OpenAPI::OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str);

		void OnGetFilesSignal(OpenAPI::OAIHttpFileElement summary);
		void OnGetFilesSignalFull(OpenAPI::OAIHttpRequestWorker* worker, OpenAPI::OAIHttpFileElement summary);
		void OnGetFilesSignalError(OpenAPI::OAIHttpFileElement summary, QNetworkReply::NetworkError error_type, QString error_str);
	};
}
