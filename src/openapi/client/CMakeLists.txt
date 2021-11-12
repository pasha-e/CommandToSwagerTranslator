cmake_minimum_required(VERSION 3.2)

#project(openapi_client)
set(TARGET_NAME openapi_client)
set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wno-unused-variable")
endif ()

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)

file(GLOB_RECURSE src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${TARGET_NAME} ${src})
#add_library(${PROJECT_NAME}
#   OAIAssembly.cpp
#   OAIAssemblyPart.cpp
#   OAIAssemblyPartSearchCriteria.cpp
#   OAIBasic_error.cpp
#   OAICoordinate.cpp
#   OAIGuid.cpp
#   OAIInline_object.cpp
#   OAIInline_response_200.cpp
#   OAILimitingBox.cpp
#   OAIWorkspace.cpp
#   OAIAssemblyApi.cpp
#   OAIAssemblyPartApi.cpp
#   OAIDefaultApi.cpp
#   OAIWorkspaceApi.cpp
#   OAIHelpers.cpp
#   OAIHttpRequest.cpp
#   OAIHttpFileElement.cpp
#)

target_link_libraries(${TARGET_NAME} PRIVATE Qt5::Core Qt5::Network )

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


#if(NOT APPLE)
#  target_link_libraries(${TARGET_NAME} PRIVATE ssl crypto)
#endif()

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TARGET_NAME} PROPERTY CXX_EXTENSIONS OFF)

install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
