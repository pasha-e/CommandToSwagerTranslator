QT += network

HEADERS += \
# Models
    $${PWD}/OAIAssembly.h \
    $${PWD}/OAIAssemblyPart.h \
    $${PWD}/OAIAssemblyPartSearchCriteria.h \
    $${PWD}/OAIBasic_error.h \
    $${PWD}/OAICoordinate.h \
    $${PWD}/OAIGuid.h \
    $${PWD}/OAIInline_response_200.h \
    $${PWD}/OAILimitingBox.h \
    $${PWD}/OAIRenderingParams.h \
    $${PWD}/OAIWorkspace.h \
# APIs
    $${PWD}/OAIAssemblyApi.h \
    $${PWD}/OAIAssemblyPartApi.h \
    $${PWD}/OAIAuthApi.h \
    $${PWD}/OAIDefaultApi.h \
    $${PWD}/OAIWorkspaceApi.h \
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
    $${PWD}/OAIBasic_error.cpp \
    $${PWD}/OAICoordinate.cpp \
    $${PWD}/OAIGuid.cpp \
    $${PWD}/OAIInline_response_200.cpp \
    $${PWD}/OAILimitingBox.cpp \
    $${PWD}/OAIRenderingParams.cpp \
    $${PWD}/OAIWorkspace.cpp \
# APIs
    $${PWD}/OAIAssemblyApi.cpp \
    $${PWD}/OAIAssemblyPartApi.cpp \
    $${PWD}/OAIAuthApi.cpp \
    $${PWD}/OAIDefaultApi.cpp \
    $${PWD}/OAIWorkspaceApi.cpp \
# Others
    $${PWD}/OAIHelpers.cpp \
    $${PWD}/OAIHttpRequest.cpp \
    $${PWD}/OAIHttpFileElement.cpp

