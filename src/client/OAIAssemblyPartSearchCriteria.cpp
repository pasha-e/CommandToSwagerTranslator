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

#include "OAIAssemblyPartSearchCriteria.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIAssemblyPartSearchCriteria::OAIAssemblyPartSearchCriteria(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIAssemblyPartSearchCriteria::OAIAssemblyPartSearchCriteria() {
    this->initializeModel();
}

OAIAssemblyPartSearchCriteria::~OAIAssemblyPartSearchCriteria() {}

void OAIAssemblyPartSearchCriteria::initializeModel() {

    m_limiting_box_isSet = false;
    m_limiting_box_isValid = false;
}

void OAIAssemblyPartSearchCriteria::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIAssemblyPartSearchCriteria::fromJsonObject(QJsonObject json) {

    m_limiting_box_isValid = ::OpenAPI::fromJsonValue(limiting_box, json[QString("limitingBox")]);
    m_limiting_box_isSet = !json[QString("limitingBox")].isNull() && m_limiting_box_isValid;
}

QString OAIAssemblyPartSearchCriteria::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIAssemblyPartSearchCriteria::asJsonObject() const {
    QJsonObject obj;
    if (limiting_box.isSet()) {
        obj.insert(QString("limitingBox"), ::OpenAPI::toJsonValue(limiting_box));
    }
    return obj;
}

OAILimitingBox OAIAssemblyPartSearchCriteria::getLimitingBox() const {
    return limiting_box;
}
void OAIAssemblyPartSearchCriteria::setLimitingBox(const OAILimitingBox &limiting_box) {
    this->limiting_box = limiting_box;
    this->m_limiting_box_isSet = true;
}

bool OAIAssemblyPartSearchCriteria::is_limiting_box_Set() const{
    return m_limiting_box_isSet;
}

bool OAIAssemblyPartSearchCriteria::is_limiting_box_Valid() const{
    return m_limiting_box_isValid;
}

bool OAIAssemblyPartSearchCriteria::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (limiting_box.isSet()) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIAssemblyPartSearchCriteria::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
