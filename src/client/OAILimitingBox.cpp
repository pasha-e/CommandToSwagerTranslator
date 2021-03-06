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

#include "OAILimitingBox.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAILimitingBox::OAILimitingBox(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAILimitingBox::OAILimitingBox() {
    this->initializeModel();
}

OAILimitingBox::~OAILimitingBox() {}

void OAILimitingBox::initializeModel() {

    m_min_isSet = false;
    m_min_isValid = false;

    m_max_isSet = false;
    m_max_isValid = false;
}

void OAILimitingBox::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAILimitingBox::fromJsonObject(QJsonObject json) {

    m_min_isValid = ::OpenAPI::fromJsonValue(min, json[QString("min")]);
    m_min_isSet = !json[QString("min")].isNull() && m_min_isValid;

    m_max_isValid = ::OpenAPI::fromJsonValue(max, json[QString("max")]);
    m_max_isSet = !json[QString("max")].isNull() && m_max_isValid;
}

QString OAILimitingBox::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAILimitingBox::asJsonObject() const {
    QJsonObject obj;
    if (min.isSet()) {
        obj.insert(QString("min"), ::OpenAPI::toJsonValue(min));
    }
    if (max.isSet()) {
        obj.insert(QString("max"), ::OpenAPI::toJsonValue(max));
    }
    return obj;
}

OAICoordinate OAILimitingBox::getMin() const {
    return min;
}
void OAILimitingBox::setMin(const OAICoordinate &min) {
    this->min = min;
    this->m_min_isSet = true;
}

bool OAILimitingBox::is_min_Set() const{
    return m_min_isSet;
}

bool OAILimitingBox::is_min_Valid() const{
    return m_min_isValid;
}

OAICoordinate OAILimitingBox::getMax() const {
    return max;
}
void OAILimitingBox::setMax(const OAICoordinate &max) {
    this->max = max;
    this->m_max_isSet = true;
}

bool OAILimitingBox::is_max_Set() const{
    return m_max_isSet;
}

bool OAILimitingBox::is_max_Valid() const{
    return m_max_isValid;
}

bool OAILimitingBox::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (min.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (max.isSet()) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAILimitingBox::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_min_isValid && m_max_isValid && true;
}

} // namespace OpenAPI
