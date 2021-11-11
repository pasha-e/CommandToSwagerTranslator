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

#include "OAIAssemblyPart.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIAssemblyPart::OAIAssemblyPart(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIAssemblyPart::OAIAssemblyPart() {
    this->initializeModel();
}

OAIAssemblyPart::~OAIAssemblyPart() {}

void OAIAssemblyPart::initializeModel() {

    m_name_isSet = false;
    m_name_isValid = false;

    m_assembly_isSet = false;
    m_assembly_isValid = false;

    m_model_guid_isSet = false;
    m_model_guid_isValid = false;

    m_limiting_box_isSet = false;
    m_limiting_box_isValid = false;
}

void OAIAssemblyPart::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIAssemblyPart::fromJsonObject(QJsonObject json) {

    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_assembly_isValid = ::OpenAPI::fromJsonValue(assembly, json[QString("assembly")]);
    m_assembly_isSet = !json[QString("assembly")].isNull() && m_assembly_isValid;

    m_model_guid_isValid = ::OpenAPI::fromJsonValue(model_guid, json[QString("modelGuid")]);
    m_model_guid_isSet = !json[QString("modelGuid")].isNull() && m_model_guid_isValid;

    m_limiting_box_isValid = ::OpenAPI::fromJsonValue(limiting_box, json[QString("limitingBox")]);
    m_limiting_box_isSet = !json[QString("limitingBox")].isNull() && m_limiting_box_isValid;
}

QString OAIAssemblyPart::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIAssemblyPart::asJsonObject() const {
    QJsonObject obj;
    if (m_name_isSet) {
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
    if (assembly.isSet()) {
        obj.insert(QString("assembly"), ::OpenAPI::toJsonValue(assembly));
    }
    if (model_guid.isSet()) {
        obj.insert(QString("modelGuid"), ::OpenAPI::toJsonValue(model_guid));
    }
    if (limiting_box.isSet()) {
        obj.insert(QString("limitingBox"), ::OpenAPI::toJsonValue(limiting_box));
    }
    return obj;
}

QString OAIAssemblyPart::getName() const {
    return name;
}
void OAIAssemblyPart::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

bool OAIAssemblyPart::is_name_Set() const{
    return m_name_isSet;
}

bool OAIAssemblyPart::is_name_Valid() const{
    return m_name_isValid;
}

OAIAssembly OAIAssemblyPart::getAssembly() const {
    return assembly;
}
void OAIAssemblyPart::setAssembly(const OAIAssembly &assembly) {
    this->assembly = assembly;
    this->m_assembly_isSet = true;
}

bool OAIAssemblyPart::is_assembly_Set() const{
    return m_assembly_isSet;
}

bool OAIAssemblyPart::is_assembly_Valid() const{
    return m_assembly_isValid;
}

OAIGuid OAIAssemblyPart::getModelGuid() const {
    return model_guid;
}
void OAIAssemblyPart::setModelGuid(const OAIGuid &model_guid) {
    this->model_guid = model_guid;
    this->m_model_guid_isSet = true;
}

bool OAIAssemblyPart::is_model_guid_Set() const{
    return m_model_guid_isSet;
}

bool OAIAssemblyPart::is_model_guid_Valid() const{
    return m_model_guid_isValid;
}

OAILimitingBox OAIAssemblyPart::getLimitingBox() const {
    return limiting_box;
}
void OAIAssemblyPart::setLimitingBox(const OAILimitingBox &limiting_box) {
    this->limiting_box = limiting_box;
    this->m_limiting_box_isSet = true;
}

bool OAIAssemblyPart::is_limiting_box_Set() const{
    return m_limiting_box_isSet;
}

bool OAIAssemblyPart::is_limiting_box_Valid() const{
    return m_limiting_box_isValid;
}

bool OAIAssemblyPart::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (assembly.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (model_guid.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (limiting_box.isSet()) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIAssemblyPart::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_name_isValid && m_assembly_isValid && m_model_guid_isValid && m_limiting_box_isValid && true;
}

} // namespace OpenAPI