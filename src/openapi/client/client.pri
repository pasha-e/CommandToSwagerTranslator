QT += network

HEADERS += \
# Models
    $${PWD}/OAIAssembly.h \
    $${PWD}/OAIAssemblyPart.h \
    $${PWD}/OAIAssemblyPartSearchCriteria.h \
    $${PWD}/OAICoordinate.h \
    $${PWD}/OAIErrorResponse.h \
    $${PWD}/OAIGuid.h \
    $${PWD}/OAIInline_object.h \
    $${PWD}/OAIInline_response_200.h \
    $${PWD}/OAIInline_response_200_1.h \
    $${PWD}/OAIInline_response_200_2.h \
    $${PWD}/OAIInline_response_201.h \
    $${PWD}/OAILimitingBox.h \
# APIs
    $${PWD}/OAIDefaultApi.h \
# Others
    $${PWD}/OAIHelpers.h \
    $${PWD}/OAIHttpRequest.h \
    $${PWD}/OAIObject.h \
    $${PWD}/OAIEnum.h \
    $${PWD}/OAIHttpFileElement.h \
    $${PWD}/OAIServerConfiguration.h \
    $${PWD}/OAIServerVariable.h

SOURCES += \
# Models
    $${PWD}/OAIAssembly.cpp \
    $${PWD}/OAIAssemblyPart.cpp \
    $${PWD}/OAIAssemblyPartSearchCriteria.cpp \
    $${PWD}/OAICoordinate.cpp \
    $${PWD}/OAIErrorResponse.cpp \
    $${PWD}/OAIGuid.cpp \
    $${PWD}/OAIInline_object.cpp \
    $${PWD}/OAIInline_response_200.cpp \
    $${PWD}/OAIInline_response_200_1.cpp \
    $${PWD}/OAIInline_response_200_2.cpp \
    $${PWD}/OAIInline_response_201.cpp \
    $${PWD}/OAILimitingBox.cpp \
# APIs
    $${PWD}/OAIDefaultApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp \
    $${PWD}/OAIHttpFileElement.cpp

