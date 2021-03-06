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

#include "OAIWorkspace.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIWorkspace::OAIWorkspace(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIWorkspace::OAIWorkspace() {
    this->initializeModel();
}

OAIWorkspace::~OAIWorkspace() {}

void OAIWorkspace::initializeModel() {

    m_id_isSet = false;
    m_id_isValid = false;

    m_name_isSet = false;
    m_name_isValid = false;

    m_simple_surface_params_isSet = false;
    m_simple_surface_params_isValid = false;

    m_full_surface_params_isSet = false;
    m_full_surface_params_isValid = false;

    m_simple_collection_params_isSet = false;
    m_simple_collection_params_isValid = false;

    m_full_collection_params_isSet = false;
    m_full_collection_params_isValid = false;

    m_show_isSet = false;
    m_show_isValid = false;

    m_file_ref_isSet = false;
    m_file_ref_isValid = false;
}

void OAIWorkspace::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIWorkspace::fromJsonObject(QJsonObject json) {

    m_id_isValid = ::OpenAPI::fromJsonValue(id, json[QString("id")]);
    m_id_isSet = !json[QString("id")].isNull() && m_id_isValid;

    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_simple_surface_params_isValid = ::OpenAPI::fromJsonValue(simple_surface_params, json[QString("simpleSurfaceParams")]);
    m_simple_surface_params_isSet = !json[QString("simpleSurfaceParams")].isNull() && m_simple_surface_params_isValid;

    m_full_surface_params_isValid = ::OpenAPI::fromJsonValue(full_surface_params, json[QString("fullSurfaceParams")]);
    m_full_surface_params_isSet = !json[QString("fullSurfaceParams")].isNull() && m_full_surface_params_isValid;

    m_simple_collection_params_isValid = ::OpenAPI::fromJsonValue(simple_collection_params, json[QString("simpleCollectionParams")]);
    m_simple_collection_params_isSet = !json[QString("simpleCollectionParams")].isNull() && m_simple_collection_params_isValid;

    m_full_collection_params_isValid = ::OpenAPI::fromJsonValue(full_collection_params, json[QString("fullCollectionParams")]);
    m_full_collection_params_isSet = !json[QString("fullCollectionParams")].isNull() && m_full_collection_params_isValid;

    m_show_isValid = ::OpenAPI::fromJsonValue(show, json[QString("show")]);
    m_show_isSet = !json[QString("show")].isNull() && m_show_isValid;

    m_file_ref_isValid = ::OpenAPI::fromJsonValue(file_ref, json[QString("fileRef")]);
    m_file_ref_isSet = !json[QString("fileRef")].isNull() && m_file_ref_isValid;
}

QString OAIWorkspace::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIWorkspace::asJsonObject() const {
    QJsonObject obj;
    if (m_id_isSet) {
        obj.insert(QString("id"), ::OpenAPI::toJsonValue(id));
    }
    if (m_name_isSet) {
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
    if (simple_surface_params.isSet()) {
        obj.insert(QString("simpleSurfaceParams"), ::OpenAPI::toJsonValue(simple_surface_params));
    }
    if (full_surface_params.isSet()) {
        obj.insert(QString("fullSurfaceParams"), ::OpenAPI::toJsonValue(full_surface_params));
    }
    if (simple_collection_params.isSet()) {
        obj.insert(QString("simpleCollectionParams"), ::OpenAPI::toJsonValue(simple_collection_params));
    }
    if (full_collection_params.isSet()) {
        obj.insert(QString("fullCollectionParams"), ::OpenAPI::toJsonValue(full_collection_params));
    }
    if (m_show_isSet) {
        obj.insert(QString("show"), ::OpenAPI::toJsonValue(show));
    }
    if (m_file_ref_isSet) {
        obj.insert(QString("fileRef"), ::OpenAPI::toJsonValue(file_ref));
    }
    return obj;
}

QString OAIWorkspace::getId() const {
    return id;
}
void OAIWorkspace::setId(const QString &id) {
    this->id = id;
    this->m_id_isSet = true;
}

bool OAIWorkspace::is_id_Set() const{
    return m_id_isSet;
}

bool OAIWorkspace::is_id_Valid() const{
    return m_id_isValid;
}

QString OAIWorkspace::getName() const {
    return name;
}
void OAIWorkspace::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

bool OAIWorkspace::is_name_Set() const{
    return m_name_isSet;
}

bool OAIWorkspace::is_name_Valid() const{
    return m_name_isValid;
}

OAIRenderingParams OAIWorkspace::getSimpleSurfaceParams() const {
    return simple_surface_params;
}
void OAIWorkspace::setSimpleSurfaceParams(const OAIRenderingParams &simple_surface_params) {
    this->simple_surface_params = simple_surface_params;
    this->m_simple_surface_params_isSet = true;
}

bool OAIWorkspace::is_simple_surface_params_Set() const{
    return m_simple_surface_params_isSet;
}

bool OAIWorkspace::is_simple_surface_params_Valid() const{
    return m_simple_surface_params_isValid;
}

OAIRenderingParams OAIWorkspace::getFullSurfaceParams() const {
    return full_surface_params;
}
void OAIWorkspace::setFullSurfaceParams(const OAIRenderingParams &full_surface_params) {
    this->full_surface_params = full_surface_params;
    this->m_full_surface_params_isSet = true;
}

bool OAIWorkspace::is_full_surface_params_Set() const{
    return m_full_surface_params_isSet;
}

bool OAIWorkspace::is_full_surface_params_Valid() const{
    return m_full_surface_params_isValid;
}

OAIRenderingParams OAIWorkspace::getSimpleCollectionParams() const {
    return simple_collection_params;
}
void OAIWorkspace::setSimpleCollectionParams(const OAIRenderingParams &simple_collection_params) {
    this->simple_collection_params = simple_collection_params;
    this->m_simple_collection_params_isSet = true;
}

bool OAIWorkspace::is_simple_collection_params_Set() const{
    return m_simple_collection_params_isSet;
}

bool OAIWorkspace::is_simple_collection_params_Valid() const{
    return m_simple_collection_params_isValid;
}

OAIRenderingParams OAIWorkspace::getFullCollectionParams() const {
    return full_collection_params;
}
void OAIWorkspace::setFullCollectionParams(const OAIRenderingParams &full_collection_params) {
    this->full_collection_params = full_collection_params;
    this->m_full_collection_params_isSet = true;
}

bool OAIWorkspace::is_full_collection_params_Set() const{
    return m_full_collection_params_isSet;
}

bool OAIWorkspace::is_full_collection_params_Valid() const{
    return m_full_collection_params_isValid;
}

bool OAIWorkspace::isShow() const {
    return show;
}
void OAIWorkspace::setShow(const bool &show) {
    this->show = show;
    this->m_show_isSet = true;
}

bool OAIWorkspace::is_show_Set() const{
    return m_show_isSet;
}

bool OAIWorkspace::is_show_Valid() const{
    return m_show_isValid;
}

QString OAIWorkspace::getFileRef() const {
    return file_ref;
}
void OAIWorkspace::setFileRef(const QString &file_ref) {
    this->file_ref = file_ref;
    this->m_file_ref_isSet = true;
}

bool OAIWorkspace::is_file_ref_Set() const{
    return m_file_ref_isSet;
}

bool OAIWorkspace::is_file_ref_Valid() const{
    return m_file_ref_isValid;
}

bool OAIWorkspace::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_id_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (simple_surface_params.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (full_surface_params.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (simple_collection_params.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (full_collection_params.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (m_show_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_file_ref_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIWorkspace::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_id_isValid && m_name_isValid && m_simple_surface_params_isValid && m_full_surface_params_isValid && m_simple_collection_params_isValid && m_full_collection_params_isValid && m_show_isValid && m_file_ref_isValid && true;
}

} // namespace OpenAPI
