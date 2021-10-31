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

#include "OAIInline_response_200.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIInline_response_200::OAIInline_response_200(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIInline_response_200::OAIInline_response_200() {
    this->initializeModel();
}

OAIInline_response_200::~OAIInline_response_200() {}

void OAIInline_response_200::initializeModel() {

    m_assemblies_isSet = false;
    m_assemblies_isValid = false;
}

void OAIInline_response_200::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIInline_response_200::fromJsonObject(QJsonObject json) {

    m_assemblies_isValid = ::OpenAPI::fromJsonValue(assemblies, json[QString("assemblies")]);
    m_assemblies_isSet = !json[QString("assemblies")].isNull() && m_assemblies_isValid;
}

QString OAIInline_response_200::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIInline_response_200::asJsonObject() const {
    QJsonObject obj;
    if (assemblies.size() > 0) {
        obj.insert(QString("assemblies"), ::OpenAPI::toJsonValue(assemblies));
    }
    return obj;
}

QList<OAIAssembly> OAIInline_response_200::getAssemblies() const {
    return assemblies;
}
void OAIInline_response_200::setAssemblies(const QList<OAIAssembly> &assemblies) {
    this->assemblies = assemblies;
    this->m_assemblies_isSet = true;
}

bool OAIInline_response_200::is_assemblies_Set() const{
    return m_assemblies_isSet;
}

bool OAIInline_response_200::is_assemblies_Valid() const{
    return m_assemblies_isValid;
}

bool OAIInline_response_200::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (assemblies.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIInline_response_200::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
