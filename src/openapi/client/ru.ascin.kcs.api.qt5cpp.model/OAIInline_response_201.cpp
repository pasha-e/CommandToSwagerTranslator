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

#include "OAIInline_response_201.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIInline_response_201::OAIInline_response_201(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIInline_response_201::OAIInline_response_201() {
    this->initializeModel();
}

OAIInline_response_201::~OAIInline_response_201() {}

void OAIInline_response_201::initializeModel() {

    m_assemblies_isSet = false;
    m_assemblies_isValid = false;

    m__isSet = false;
    m__isValid = false;
}

void OAIInline_response_201::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIInline_response_201::fromJsonObject(QJsonObject json) {

    m_assemblies_isValid = ::OpenAPI::fromJsonValue(assemblies, json[QString("assemblies")]);
    m_assemblies_isSet = !json[QString("assemblies")].isNull() && m_assemblies_isValid;

    m__isValid = ::OpenAPI::fromJsonValue(, json[QString("")]);
    m__isSet = !json[QString("")].isNull() && m__isValid;
}

QString OAIInline_response_201::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIInline_response_201::asJsonObject() const {
    QJsonObject obj;
    if (assemblies.size() > 0) {
        obj.insert(QString("assemblies"), ::OpenAPI::toJsonValue(assemblies));
    }
    if (m__isSet) {
        obj.insert(QString(""), ::OpenAPI::toJsonValue());
    }
    return obj;
}

QList<OAIAssembly> OAIInline_response_201::getAssemblies() const {
    return assemblies;
}
void OAIInline_response_201::setAssemblies(const QList<OAIAssembly> &assemblies) {
    this->assemblies = assemblies;
    this->m_assemblies_isSet = true;
}

bool OAIInline_response_201::is_assemblies_Set() const{
    return m_assemblies_isSet;
}

bool OAIInline_response_201::is_assemblies_Valid() const{
    return m_assemblies_isValid;
}

QString OAIInline_response_201::get() const {
    return ;
}
void OAIInline_response_201::set(const QString &) {
    this-> = ;
    this->m__isSet = true;
}

bool OAIInline_response_201::is__Set() const{
    return m__isSet;
}

bool OAIInline_response_201::is__Valid() const{
    return m__isValid;
}

bool OAIInline_response_201::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (assemblies.size() > 0) {
            isObjectUpdated = true;
            break;
        }

        if (m__isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIInline_response_201::isValid() const {
    // only required properties are required for the object to be considered valid
    return true;
}

} // namespace OpenAPI
