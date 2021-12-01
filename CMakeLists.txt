cmake_minimum_required(VERSION 3.14)

project(CommandToSwagerTranslator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt5Network REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Core Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)
find_package(OpenSSL REQUIRED)

if( OPENSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    message(STATUS "OPENSSL_INCLUDE_DIRS ${OPENSSL_INCLUDE_DIRS}")
    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
endif()
 
#target_link_libraries(${YOUR_TARGET_HERE} ${OPENSSL_LIBRARIES})

find_package(Qt5 REQUIRED COMPONENTS Core Network)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${SRC})
add_executable(CommandToSwagerTranslator ${SRC})

add_subdirectory(src/client)
        
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

target_link_libraries(CommandToSwagerTranslator PRIVATE client Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network OpenSSL::SSL OpenSSL::Crypto)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)