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

#include "OAIInline_response_200_1.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIInline_response_200_1::OAIInline_response_200_1(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIInline_response_200_1::OAIInline_response_200_1() {
    this->initializeModel();
}

OAIInline_response_200_1::~OAIInline_response_200_1() {}

void OAIInline_response_200_1::initializeModel() {

    m_parts_isSet = false;
    m_parts_isValid = false;
}

void OAIInline_response_200_1::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIInline_response_200_1::fromJsonObject(QJsonObject json) {

    m_parts_isValid = ::OpenAPI::fromJsonValue(parts, json[QString("parts")]);
    m_parts_isSet = !json[QString("parts")].isNull() && m_parts_isValid;
}

QString OAIInline_response_200_1::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIInline_response_200_1::asJsonObject() const {
    QJsonObject obj;
    if (parts.size() > 0) {
        obj.insert(QString("parts"), ::OpenAPI::toJsonValue(parts));
    }
    return obj;
}

QList<OAIAssemblyPart> OAIInline_response_200_1::getParts() const {
    return parts;
}
void OAIInline_response_200_1::setParts(const QList<OAIAssemblyPart> &parts) {
    this->parts = parts;
    this->m_parts_isSet = true;
}

bool OAIInline_response_200_1::is_parts_Set() const{
    return m_parts_isSet;
}

bool OAIInline_response_200_1::is_parts_Valid() const{
    return m_parts_isValid;
}

bool OAIInline_response_200_1::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (parts.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIInline_response_200_1::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
