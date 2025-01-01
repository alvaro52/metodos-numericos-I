add_library(tinyexpr STATIC tinyexpr.c)

target_include_directories(tinyexpr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})