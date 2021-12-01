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

find_package(Qt5 REQUIRED COMPONENTS Core Network)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h  
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${SRC})
add_executable(CommandToSwagerTranslator ${SRC})


add_subdirectory(src/client)
#add_subdirectory(src/tcp_server)

#target_link_libraries(${TARGET_NAME} 
#        tcp_server 
#        client 
#        Qt5::Core 
#        Qt5::Network
#        OpenSSL::SSL
#        OpenSSL::Crypto
#        )
        
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

target_link_libraries(CommandToSwagerTranslator PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network OpenSSL::SSL OpenSSL::Crypto)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)