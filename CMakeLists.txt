cmake_minimum_required(VERSION 3.10)
project(CarRentalSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(CarRentalSystem ${SOURCES})

# Optionally, copy .txt files to build directory after build
file(GLOB TXT_FILES "${CMAKE_SOURCE_DIR}/src/*.txt")
foreach(txt_file ${TXT_FILES})
    add_custom_command(TARGET CarRentalSystem POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${txt_file} $<TARGET_FILE_DIR:CarRentalSystem>
    )
endforeach()