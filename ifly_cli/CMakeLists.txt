cmake_minimum_required(VERSION 3.16)
project(ifly_cli)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler flags for Windows
if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/../737MAX_SDK)
include_directories(${CMAKE_SOURCE_DIR}/../737MAX_SDK/sdk)

# Source files
set(SOURCES
    main.cpp
)

# Create executable
add_executable(ifly_cli ${SOURCES})

# Link libraries
if(WIN32)
    target_link_libraries(ifly_cli
        user32
        kernel32
    )
endif()

# Set output directory
set_target_properties(ifly_cli PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy to root directory for easier access
add_custom_command(TARGET ifly_cli POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ifly_cli> ${CMAKE_SOURCE_DIR}/../
)
