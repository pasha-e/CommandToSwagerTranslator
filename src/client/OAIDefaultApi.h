/**
 * KCS API
 * KCS API
 *
 * The version of the OpenAPI document: 1.0
 * Contact: modievskii_av@ascon.ru
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#ifndef OAI_OAIDefaultApi_H
#define OAI_OAIDefaultApi_H

#include "OAIHelpers.h"
#include "OAIHttpRequest.h"
#include "OAIServerConfiguration.h"

#include "OAIBasic_error.h"
#include "OAIInline_object.h"
#include "OAIInline_response_200.h"
#include "OAIObject.h"
#include "OAIWorkspace.h"
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include <QNetworkAccessManager>

namespace OpenAPI {

class OAIDefaultApi : public QObject {
    Q_OBJECT

public:
    OAIDefaultApi(const int timeOut = 0);
    ~OAIDefaultApi();

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
    * @param[in]  guid QString [required]
    */
    void assembly_post(const QString &guid);

    /**
    * @param[in]  content_type_application_x_www_form_urlencoded QString [required]
    * @param[in]  authorization_basic_clientsecret QString [required]
    * @param[in]  oai_inline_object OAIInline_object [optional]
    */
    void postOauthToken(const QString &content_type_application_x_www_form_urlencoded, const QString &authorization_basic_clientsecret, const ::OpenAPI::OptionalParam<OAIInline_object> &oai_inline_object = ::OpenAPI::OptionalParam<OAIInline_object>());

    /**
    * @param[in]  guid QString [required]
    * @param[in]  fetch_plan QString [optional]
    */
    void workspace_getById(const QString &guid, const ::OpenAPI::OptionalParam<QString> &fetch_plan = ::OpenAPI::OptionalParam<QString>());


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

    void assembly_postCallback(OAIHttpRequestWorker *worker);
    void postOauthTokenCallback(OAIHttpRequestWorker *worker);
    void workspace_getByIdCallback(OAIHttpRequestWorker *worker);

signals:

    void assembly_postSignal();
    void postOauthTokenSignal(OAIInline_response_200 summary);
    void workspace_getByIdSignal(OAIWorkspace summary);

    void assembly_postSignalFull(OAIHttpRequestWorker *worker);
    void postOauthTokenSignalFull(OAIHttpRequestWorker *worker, OAIInline_response_200 summary);
    void workspace_getByIdSignalFull(OAIHttpRequestWorker *worker, OAIWorkspace summary);

    void assembly_postSignalE(QNetworkReply::NetworkError error_type, QString error_str);
    void postOauthTokenSignalE(OAIInline_response_200 summary, QNetworkReply::NetworkError error_type, QString error_str);
    void workspace_getByIdSignalE(OAIWorkspace summary, QNetworkReply::NetworkError error_type, QString error_str);

    void assembly_postSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void postOauthTokenSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void workspace_getByIdSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal();
    void allPendingRequestsCompleted();
};

} // namespace OpenAPI
#endif