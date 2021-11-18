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

#include "OAIBasic_error.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIBasic_error::OAIBasic_error(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIBasic_error::OAIBasic_error() {
    this->initializeModel();
}

OAIBasic_error::~OAIBasic_error() {}

void OAIBasic_error::initializeModel() {

    m_message_isSet = false;
    m_message_isValid = false;

    m_status_isSet = false;
    m_status_isValid = false;

    m_url_isSet = false;
    m_url_isValid = false;

    m_documentation_url_isSet = false;
    m_documentation_url_isValid = false;
}

void OAIBasic_error::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIBasic_error::fromJsonObject(QJsonObject json) {

    m_message_isValid = ::OpenAPI::fromJsonValue(message, json[QString("message")]);
    m_message_isSet = !json[QString("message")].isNull() && m_message_isValid;

    m_status_isValid = ::OpenAPI::fromJsonValue(status, json[QString("status")]);
    m_status_isSet = !json[QString("status")].isNull() && m_status_isValid;

    m_url_isValid = ::OpenAPI::fromJsonValue(url, json[QString("url")]);
    m_url_isSet = !json[QString("url")].isNull() && m_url_isValid;

    m_documentation_url_isValid = ::OpenAPI::fromJsonValue(documentation_url, json[QString("documentation_url")]);
    m_documentation_url_isSet = !json[QString("documentation_url")].isNull() && m_documentation_url_isValid;
}

QString OAIBasic_error::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIBasic_error::asJsonObject() const {
    QJsonObject obj;
    if (m_message_isSet) {
        obj.insert(QString("message"), ::OpenAPI::toJsonValue(message));
    }
    if (m_status_isSet) {
        obj.insert(QString("status"), ::OpenAPI::toJsonValue(status));
    }
    if (m_url_isSet) {
        obj.insert(QString("url"), ::OpenAPI::toJsonValue(url));
    }
    if (m_documentation_url_isSet) {
        obj.insert(QString("documentation_url"), ::OpenAPI::toJsonValue(documentation_url));
    }
    return obj;
}

QString OAIBasic_error::getMessage() const {
    return message;
}
void OAIBasic_error::setMessage(const QString &message) {
    this->message = message;
    this->m_message_isSet = true;
}

bool OAIBasic_error::is_message_Set() const{
    return m_message_isSet;
}

bool OAIBasic_error::is_message_Valid() const{
    return m_message_isValid;
}

QString OAIBasic_error::getStatus() const {
    return status;
}
void OAIBasic_error::setStatus(const QString &status) {
    this->status = status;
    this->m_status_isSet = true;
}

bool OAIBasic_error::is_status_Set() const{
    return m_status_isSet;
}

bool OAIBasic_error::is_status_Valid() const{
    return m_status_isValid;
}

QString OAIBasic_error::getUrl() const {
    return url;
}
void OAIBasic_error::setUrl(const QString &url) {
    this->url = url;
    this->m_url_isSet = true;
}

bool OAIBasic_error::is_url_Set() const{
    return m_url_isSet;
}

bool OAIBasic_error::is_url_Valid() const{
    return m_url_isValid;
}

QString OAIBasic_error::getDocumentationUrl() const {
    return documentation_url;
}
void OAIBasic_error::setDocumentationUrl(const QString &documentation_url) {
    this->documentation_url = documentation_url;
    this->m_documentation_url_isSet = true;
}

bool OAIBasic_error::is_documentation_url_Set() const{
    return m_documentation_url_isSet;
}

bool OAIBasic_error::is_documentation_url_Valid() const{
    return m_documentation_url_isValid;
}

bool OAIBasic_error::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_message_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_status_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_url_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_documentation_url_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIBasic_error::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
