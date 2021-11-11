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

#include "OAICoordinate.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAICoordinate::OAICoordinate(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAICoordinate::OAICoordinate() {
    this->initializeModel();
}

OAICoordinate::~OAICoordinate() {}

void OAICoordinate::initializeModel() {

    m_x_isSet = false;
    m_x_isValid = false;

    m_y_isSet = false;
    m_y_isValid = false;

    m_z_isSet = false;
    m_z_isValid = false;
}

void OAICoordinate::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAICoordinate::fromJsonObject(QJsonObject json) {

    m_x_isValid = ::OpenAPI::fromJsonValue(x, json[QString("x")]);
    m_x_isSet = !json[QString("x")].isNull() && m_x_isValid;

    m_y_isValid = ::OpenAPI::fromJsonValue(y, json[QString("y")]);
    m_y_isSet = !json[QString("y")].isNull() && m_y_isValid;

    m_z_isValid = ::OpenAPI::fromJsonValue(z, json[QString("z")]);
    m_z_isSet = !json[QString("z")].isNull() && m_z_isValid;
}

QString OAICoordinate::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAICoordinate::asJsonObject() const {
    QJsonObject obj;
    if (m_x_isSet) {
        obj.insert(QString("x"), ::OpenAPI::toJsonValue(x));
    }
    if (m_y_isSet) {
        obj.insert(QString("y"), ::OpenAPI::toJsonValue(y));
    }
    if (m_z_isSet) {
        obj.insert(QString("z"), ::OpenAPI::toJsonValue(z));
    }
    return obj;
}

double OAICoordinate::getX() const {
    return x;
}
void OAICoordinate::setX(const double &x) {
    this->x = x;
    this->m_x_isSet = true;
}

bool OAICoordinate::is_x_Set() const{
    return m_x_isSet;
}

bool OAICoordinate::is_x_Valid() const{
    return m_x_isValid;
}

double OAICoordinate::getY() const {
    return y;
}
void OAICoordinate::setY(const double &y) {
    this->y = y;
    this->m_y_isSet = true;
}

bool OAICoordinate::is_y_Set() const{
    return m_y_isSet;
}

bool OAICoordinate::is_y_Valid() const{
    return m_y_isValid;
}

double OAICoordinate::getZ() const {
    return z;
}
void OAICoordinate::setZ(const double &z) {
    this->z = z;
    this->m_z_isSet = true;
}

bool OAICoordinate::is_z_Set() const{
    return m_z_isSet;
}

bool OAICoordinate::is_z_Valid() const{
    return m_z_isValid;
}

bool OAICoordinate::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_x_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_y_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_z_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAICoordinate::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_x_isValid && m_y_isValid && m_z_isValid && true;
}

} // namespace OpenAPI