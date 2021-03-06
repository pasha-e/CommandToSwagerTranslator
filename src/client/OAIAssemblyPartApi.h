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

#ifndef OAI_OAIAssemblyPartApi_H
#define OAI_OAIAssemblyPartApi_H

#include "OAIHelpers.h"
#include "OAIHttpRequest.h"
#include "OAIServerConfiguration.h"

#include "OAIAssemblyPart.h"
#include "OAIAssemblyPartSearchCriteria.h"
#include "OAIBasic_error.h"
#include "OAIObject.h"
#include <QString>

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QList>
#include <QNetworkAccessManager>

namespace OpenAPI {

class OAIAssemblyPartApi : public QObject {
    Q_OBJECT

public:
    OAIAssemblyPartApi(const int timeOut = 0);
    ~OAIAssemblyPartApi();

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
    * @param[in]  oai_assembly_part_search_criteria OAIAssemblyPartSearchCriteria [optional]
    */
    void assemblyPart_getByCriteria(const ::OpenAPI::OptionalParam<OAIAssemblyPartSearchCriteria> &oai_assembly_part_search_criteria = ::OpenAPI::OptionalParam<OAIAssemblyPartSearchCriteria>());

    /**
    * @param[in]  guid QString [required]
    */
    void assemblyPart_getByGuid(const QString &guid);


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

    void assemblyPart_getByCriteriaCallback(OAIHttpRequestWorker *worker);
    void assemblyPart_getByGuidCallback(OAIHttpRequestWorker *worker);

signals:

    void assemblyPart_getByCriteriaSignal(QList<OAIAssemblyPart> summary);
    void assemblyPart_getByGuidSignal(OAIAssemblyPart summary);

    void assemblyPart_getByCriteriaSignalFull(OAIHttpRequestWorker *worker, QList<OAIAssemblyPart> summary);
    void assemblyPart_getByGuidSignalFull(OAIHttpRequestWorker *worker, OAIAssemblyPart summary);

    void assemblyPart_getByCriteriaSignalE(QList<OAIAssemblyPart> summary, QNetworkReply::NetworkError error_type, QString error_str);
    void assemblyPart_getByGuidSignalE(OAIAssemblyPart summary, QNetworkReply::NetworkError error_type, QString error_str);

    void assemblyPart_getByCriteriaSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);
    void assemblyPart_getByGuidSignalEFull(OAIHttpRequestWorker *worker, QNetworkReply::NetworkError error_type, QString error_str);

    void abortRequestsSignal();
    void allPendingRequestsCompleted();
};

} // namespace OpenAPI
#endif
