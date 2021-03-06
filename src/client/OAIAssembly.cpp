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

#include "OAIAssembly.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIAssembly::OAIAssembly(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIAssembly::OAIAssembly() {
    this->initializeModel();
}

OAIAssembly::~OAIAssembly() {}

void OAIAssembly::initializeModel() {

    m_name_isSet = false;
    m_name_isValid = false;

    m_model_guid_isSet = false;
    m_model_guid_isValid = false;

    m_date_time_isSet = false;
    m_date_time_isValid = false;

    m_hash_isSet = false;
    m_hash_isValid = false;
}

void OAIAssembly::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIAssembly::fromJsonObject(QJsonObject json) {

    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_model_guid_isValid = ::OpenAPI::fromJsonValue(model_guid, json[QString("modelGuid")]);
    m_model_guid_isSet = !json[QString("modelGuid")].isNull() && m_model_guid_isValid;

    m_date_time_isValid = ::OpenAPI::fromJsonValue(date_time, json[QString("dateTime")]);
    m_date_time_isSet = !json[QString("dateTime")].isNull() && m_date_time_isValid;

    m_hash_isValid = ::OpenAPI::fromJsonValue(hash, json[QString("hash")]);
    m_hash_isSet = !json[QString("hash")].isNull() && m_hash_isValid;
}

QString OAIAssembly::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIAssembly::asJsonObject() const {
    QJsonObject obj;
    if (m_name_isSet) {
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
    if (model_guid.isSet()) {
        obj.insert(QString("modelGuid"), ::OpenAPI::toJsonValue(model_guid));
    }
    if (m_date_time_isSet) {
        obj.insert(QString("dateTime"), ::OpenAPI::toJsonValue(date_time));
    }
    if (m_hash_isSet) {
        obj.insert(QString("hash"), ::OpenAPI::toJsonValue(hash));
    }
    return obj;
}

QString OAIAssembly::getName() const {
    return name;
}
void OAIAssembly::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

bool OAIAssembly::is_name_Set() const{
    return m_name_isSet;
}

bool OAIAssembly::is_name_Valid() const{
    return m_name_isValid;
}

OAIGuid OAIAssembly::getModelGuid() const {
    return model_guid;
}
void OAIAssembly::setModelGuid(const OAIGuid &model_guid) {
    this->model_guid = model_guid;
    this->m_model_guid_isSet = true;
}

bool OAIAssembly::is_model_guid_Set() const{
    return m_model_guid_isSet;
}

bool OAIAssembly::is_model_guid_Valid() const{
    return m_model_guid_isValid;
}

QString OAIAssembly::getDateTime() const {
    return date_time;
}
void OAIAssembly::setDateTime(const QString &date_time) {
    this->date_time = date_time;
    this->m_date_time_isSet = true;
}

bool OAIAssembly::is_date_time_Set() const{
    return m_date_time_isSet;
}

bool OAIAssembly::is_date_time_Valid() const{
    return m_date_time_isValid;
}

QString OAIAssembly::getHash() const {
    return hash;
}
void OAIAssembly::setHash(const QString &hash) {
    this->hash = hash;
    this->m_hash_isSet = true;
}

bool OAIAssembly::is_hash_Set() const{
    return m_hash_isSet;
}

bool OAIAssembly::is_hash_Valid() const{
    return m_hash_isValid;
}

bool OAIAssembly::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (model_guid.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (m_date_time_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_hash_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIAssembly::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_name_isValid && m_model_guid_isValid && m_date_time_isValid && m_hash_isValid && true;
}

} // namespace OpenAPI
