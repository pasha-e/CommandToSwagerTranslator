set(TARGET_NAME tcp_server)

set(LIB_TYPE STATIC)

find_package(Qt5 ${SKIF_PLUGINS_QT_VERSION} REQUIRED COMPONENTS Core Network)
set(CMAKE_AUTOMOC ON)

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

set(CMAKE_AUTOMOC ON)
add_library(${TARGET_NAME} ${LIB_TYPE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${TARGET_NAME}
        Qt5::Core
		Qt5::Network        
)

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

