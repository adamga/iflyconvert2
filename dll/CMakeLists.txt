cmake_minimum_required(VERSION 3.10)
project(iflycli_dll)

add_library(iflycli_dll SHARED iflycli_dll.cpp)

target_include_directories(iflycli_dll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link to your SDK and other dependencies here if needed
# target_link_libraries(iflycli_dll ...)
