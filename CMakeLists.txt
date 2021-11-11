cmake_minimum_required(VERSION 3.0.0)
project(CommandToSwagerTranslator VERSION 0.1.0)

include(CTest)
enable_testing()
#file(GLOB_RECURSE src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
find_package(Qt5 REQUIRED Core Network)
set(CMAKE_AUTOMOC ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src)