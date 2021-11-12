set(TARGET_NAME ConsoleApp)
include(CTest)
enable_testing()
file(GLOB_RECURSE src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


find_package(Qt5 REQUIRED COMPONENTS Core Network)

set(CMAKE_AUTOMOC ON)

add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} 
        tcp_server 
        openapi_client 
        Qt5::Core 
        Qt5::Network)

        

