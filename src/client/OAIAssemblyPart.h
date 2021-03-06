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

/*
 * OAIAssemblyPart.h
 *
 * Представление элемента модели
 */

#ifndef OAIAssemblyPart_H
#define OAIAssemblyPart_H

#include <QJsonObject>

#include "OAIAssembly.h"
#include "OAIGuid.h"
#include "OAILimitingBox.h"
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIAssemblyPart : public OAIObject {
public:
    OAIAssemblyPart();
    OAIAssemblyPart(QString json);
    ~OAIAssemblyPart() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getName() const;
    void setName(const QString &name);
    bool is_name_Set() const;
    bool is_name_Valid() const;

    OAIAssembly getAssembly() const;
    void setAssembly(const OAIAssembly &assembly);
    bool is_assembly_Set() const;
    bool is_assembly_Valid() const;

    OAIGuid getModelGuid() const;
    void setModelGuid(const OAIGuid &model_guid);
    bool is_model_guid_Set() const;
    bool is_model_guid_Valid() const;

    OAILimitingBox getLimitingBox() const;
    void setLimitingBox(const OAILimitingBox &limiting_box);
    bool is_limiting_box_Set() const;
    bool is_limiting_box_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString name;
    bool m_name_isSet;
    bool m_name_isValid;

    OAIAssembly assembly;
    bool m_assembly_isSet;
    bool m_assembly_isValid;

    OAIGuid model_guid;
    bool m_model_guid_isSet;
    bool m_model_guid_isValid;

    OAILimitingBox limiting_box;
    bool m_limiting_box_isSet;
    bool m_limiting_box_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIAssemblyPart)

#endif // OAIAssemblyPart_H
