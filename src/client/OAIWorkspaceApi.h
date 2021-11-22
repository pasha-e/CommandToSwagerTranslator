/**
 * KCS API
 * KOMPAS Collaboration Service API
 *
 * The version of the OpenAPI document: 1.0
 * Contact: modievskii_av@ascon.ru
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#ifndef OAI_OAIWorkspaceApi_H
#define OAI_OAIWorkspaceApi_H

#include "OAIHelpers.h"
#include "OAIHttpRequest.h"
#include "OAIServerConfiguration.h"

#include "OAIBasic_error.h"
#include "OAIObject.h"
#include "OAIWorkspace.h"
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include <QNetworkAccessManager>

namespace OpenAPI {

class OAIWorkspaceApi : public QObject {
    Q_OBJECT

public:
    OAIWorkspaceApi(const int timeOut = 0);
    ~OAIWorkspaceApi();

    void initializeServerConfigs();
    int setDefaultServerValue(int serverIndex,const QString &operation, const QString &variable,const QString &val);
    void setServerIndex(const QString &operation, int serverIndex);
    void setApiKey(const QString &apiKeyName, const QString &apiKey);
    void setBearerToken(const QString &token);
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    void setTimeOut(const int timeOut);
    void setWorkingDirectory(const QString &path);
    void setNetworkAccessManager(QNetworkAccessManager* manager);
    int addServerConfiguration(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables = QMap<QString, OAIServerVariable>());
    void setNewServerForAllOperations(const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables =  QMap<QString, OAIServerVariable>());
    void setNewServer(const QString &operation, const QUrl &url, const QString &description = "", const QMap<QString, OAIServerVariable> &variables =  QMap<QString, OAIServerVariable>());
    void addHeaders(const QString &key, const QString &value);
    void enableRequestCompression();
    void enableResponseCompression();
    void abortRequests();
    QString getParamStylePrefix(QString style);
    QString getParamStyleSuffix(QString style);
    QString getParamStyleDelimiter(QString style, QString name, bool isExplode);

    /**
    * @param[in]  project_id QString [required]
    * @param[in]  fetch_plan QString [optional]
    * @param[in]  limit QString [optional]
    * @param[in]  offset QString [optional]
    * @param[in]  sort QString [optional]
    */
    void workspace_getListWorkspace(const QString &project_id, const ::OpenAPI::OptionalParam<QString> &fetch_plan = ::OpenAPI::OptionalParam<QString>(), const ::OpenAPI::OptionalParam<QString> &limit = ::OpenAPI::OptionalParam<QString>(), const ::OpenAPI::OptionalParam<QString> &offset = ::OpenAPI::OptionalParam<QString>(), const ::OpenAPI::OptionalParam<QString> &sort = ::OpenAPI::OptionalParam<QString>());

    /**
    * @param[in]  guid QString [required]
    * @param[in]  oai_workspace OAIWorkspace [optional]
    */
    void workspace_post(const QString &guid, const ::OpenAPI::OptionalParam<OAIWorkspace> &oai_workspace = ::OpenAPI::OptionalParam<OAIWorkspace>());


private:
    QMap<QString,int> _serverIndices;
    QMap<QString,QList<OAIServerConfiguration>> _serverConfigs;
    QMap<QString, QString> _apiKeys;
    QString _bearerToken;
    QString _username;
    QString _password;
    int _timeOut;
    QString _workingDirectory;
    QNetworkAccessManager* _manager;
    QMap<QString, QString> defaultHeaders;
    bool isResponseCompressionEnabled;
    bool isRequestCompressionEnabled;

    void workspace_getListWorkspaceCallback(OAIHttpRequestWorker *worker);
    void workspace_postCallback(OAIHttpRequestWorker *worker);

signals:

    void workspace_getListWorkspaceSignal(QList<OAIWorkspace> summary);
    void workspace_postSignal();

    void workspace_getListWorkspaceSignalFull(OAIHttpRequestWorker *worker, QList<OAIWorkspace> summary);
    void workspace_postSignalFull(OAIHttpRequestWorker *worker);

    void workspace_getListWorkspaceSignalE(QList<OAIWorkspace> summary, QNetworkReply::NetworkError error_type, QString error_str);
    void workspace_postSignalE(QNetworkReply::NetworkError error_type, QString error_str);

    void workspace_getListWorkspaceSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void workspace_postSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal();
    void allPendingRequestsCompleted();
};

} // namespace OpenAPI
#endif
