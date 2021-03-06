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
 * OAIInline_response_201.h
 *
 * 
 */

#ifndef OAIInline_response_201_H
#define OAIInline_response_201_H

#include <QJsonObject>

#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIInline_response_201 : public OAIObject {
public:
    OAIInline_response_201();
    OAIInline_response_201(QString json);
    ~OAIInline_response_201() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getFileRef() const;
    void setFileRef(const QString &file_ref);
    bool is_file_ref_Set() const;
    bool is_file_ref_Valid() const;

    QString getName() const;
    void setName(const QString &name);
    bool is_name_Set() const;
    bool is_name_Valid() const;

    double getSize() const;
    void setSize(const double &size);
    bool is_size_Set() const;
    bool is_size_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString file_ref;
    bool m_file_ref_isSet;
    bool m_file_ref_isValid;

    QString name;
    bool m_name_isSet;
    bool m_name_isValid;

    double size;
    bool m_size_isSet;
    bool m_size_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIInline_response_201)

#endif // OAIInline_response_201_H
