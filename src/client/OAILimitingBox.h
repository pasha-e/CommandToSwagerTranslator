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
 * OAILimitingBox.h
 *
 * Габарит - координаты диагональных точек параллелепипеда, описывающего точную электронную модель составной части изделия, в системе координат модели составной части (одна из диагональных точек может быть в нуле системы координат).
 */

#ifndef OAILimitingBox_H
#define OAILimitingBox_H

#include <QJsonObject>

#include "OAICoordinate.h"

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAILimitingBox : public OAIObject {
public:
    OAILimitingBox();
    OAILimitingBox(QString json);
    ~OAILimitingBox() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    OAICoordinate getMin() const;
    void setMin(const OAICoordinate &min);
    bool is_min_Set() const;
    bool is_min_Valid() const;

    OAICoordinate getMax() const;
    void setMax(const OAICoordinate &max);
    bool is_max_Set() const;
    bool is_max_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    OAICoordinate min;
    bool m_min_isSet;
    bool m_min_isValid;

    OAICoordinate max;
    bool m_max_isSet;
    bool m_max_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAILimitingBox)

#endif // OAILimitingBox_H
