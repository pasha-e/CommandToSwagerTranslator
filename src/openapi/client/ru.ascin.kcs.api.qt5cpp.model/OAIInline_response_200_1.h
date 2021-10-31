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

/*
 * OAIInline_response_200_1.h
 *
 * 
 */

#ifndef OAIInline_response_200_1_H
#define OAIInline_response_200_1_H

#include <QJsonObject>

#include "ru.ascin.kcs.api.qt5cpp.model\OAIAssemblyPart.h"
#include <QList>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_200_1 : public OAIObject {
public:
    OAIInline_response_200_1();
    OAIInline_response_200_1(QString json);
    ~OAIInline_response_200_1() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QList<OAIAssemblyPart> getParts() const;
    void setParts(const QList<OAIAssemblyPart> &parts);
    bool is_parts_Set() const;
    bool is_parts_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QList<OAIAssemblyPart> parts;
    bool m_parts_isSet;
    bool m_parts_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_200_1)

#endif // OAIInline_response_200_1_H
