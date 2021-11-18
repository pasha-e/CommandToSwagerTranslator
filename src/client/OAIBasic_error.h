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
 * OAIBasic_error.h
 *
 * 
 */

#ifndef OAIBasic_error_H
#define OAIBasic_error_H

#include <QJsonObject>

#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIBasic_error : public OAIObject {
public:
    OAIBasic_error();
    OAIBasic_error(QString json);
    ~OAIBasic_error() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getMessage() const;
    void setMessage(const QString &message);
    bool is_message_Set() const;
    bool is_message_Valid() const;

    QString getStatus() const;
    void setStatus(const QString &status);
    bool is_status_Set() const;
    bool is_status_Valid() const;

    QString getUrl() const;
    void setUrl(const QString &url);
    bool is_url_Set() const;
    bool is_url_Valid() const;

    QString getDocumentationUrl() const;
    void setDocumentationUrl(const QString &documentation_url);
    bool is_documentation_url_Set() const;
    bool is_documentation_url_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString message;
    bool m_message_isSet;
    bool m_message_isValid;

    QString status;
    bool m_status_isSet;
    bool m_status_isValid;

    QString url;
    bool m_url_isSet;
    bool m_url_isValid;

    QString documentation_url;
    bool m_documentation_url_isSet;
    bool m_documentation_url_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIBasic_error)

#endif // OAIBasic_error_H
