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

#include "OAIRenderingParams.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIRenderingParams::OAIRenderingParams(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIRenderingParams::OAIRenderingParams() {
    this->initializeModel();
}

OAIRenderingParams::~OAIRenderingParams() {}

void OAIRenderingParams::initializeModel() {

    m_red_isSet = false;
    m_red_isValid = false;

    m_green_isSet = false;
    m_green_isValid = false;

    m_blue_isSet = false;
    m_blue_isValid = false;

    m_transparency_isSet = false;
    m_transparency_isValid = false;
}

void OAIRenderingParams::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIRenderingParams::fromJsonObject(QJsonObject json) {

    m_red_isValid = ::OpenAPI::fromJsonValue(red, json[QString("red")]);
    m_red_isSet = !json[QString("red")].isNull() && m_red_isValid;

    m_green_isValid = ::OpenAPI::fromJsonValue(green, json[QString("green")]);
    m_green_isSet = !json[QString("green")].isNull() && m_green_isValid;

    m_blue_isValid = ::OpenAPI::fromJsonValue(blue, json[QString("blue")]);
    m_blue_isSet = !json[QString("blue")].isNull() && m_blue_isValid;

    m_transparency_isValid = ::OpenAPI::fromJsonValue(transparency, json[QString("transparency")]);
    m_transparency_isSet = !json[QString("transparency")].isNull() && m_transparency_isValid;
}

QString OAIRenderingParams::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIRenderingParams::asJsonObject() const {
    QJsonObject obj;
    if (m_red_isSet) {
        obj.insert(QString("red"), ::OpenAPI::toJsonValue(red));
    }
    if (m_green_isSet) {
        obj.insert(QString("green"), ::OpenAPI::toJsonValue(green));
    }
    if (m_blue_isSet) {
        obj.insert(QString("blue"), ::OpenAPI::toJsonValue(blue));
    }
    if (m_transparency_isSet) {
        obj.insert(QString("transparency"), ::OpenAPI::toJsonValue(transparency));
    }
    return obj;
}

double OAIRenderingParams::getRed() const {
    return red;
}
void OAIRenderingParams::setRed(const double &red) {
    this->red = red;
    this->m_red_isSet = true;
}

bool OAIRenderingParams::is_red_Set() const{
    return m_red_isSet;
}

bool OAIRenderingParams::is_red_Valid() const{
    return m_red_isValid;
}

double OAIRenderingParams::getGreen() const {
    return green;
}
void OAIRenderingParams::setGreen(const double &green) {
    this->green = green;
    this->m_green_isSet = true;
}

bool OAIRenderingParams::is_green_Set() const{
    return m_green_isSet;
}

bool OAIRenderingParams::is_green_Valid() const{
    return m_green_isValid;
}

double OAIRenderingParams::getBlue() const {
    return blue;
}
void OAIRenderingParams::setBlue(const double &blue) {
    this->blue = blue;
    this->m_blue_isSet = true;
}

bool OAIRenderingParams::is_blue_Set() const{
    return m_blue_isSet;
}

bool OAIRenderingParams::is_blue_Valid() const{
    return m_blue_isValid;
}

double OAIRenderingParams::getTransparency() const {
    return transparency;
}
void OAIRenderingParams::setTransparency(const double &transparency) {
    this->transparency = transparency;
    this->m_transparency_isSet = true;
}

bool OAIRenderingParams::is_transparency_Set() const{
    return m_transparency_isSet;
}

bool OAIRenderingParams::is_transparency_Valid() const{
    return m_transparency_isValid;
}

bool OAIRenderingParams::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_red_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_green_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_blue_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_transparency_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIRenderingParams::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_red_isValid && m_green_isValid && m_blue_isValid && m_transparency_isValid && true;
}

} // namespace OpenAPI
