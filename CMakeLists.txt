cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 26)

project(numerical_methods_I)

add_subdirectory(thirdparty/tinyexpr)
add_subdirectory(thirdparty/eigen)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}" ${MY_SOURCES})

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 26)

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES} )

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE tinyexpr Eigen3::Eigen)
