cmake_minimum_required(VERSION 3.5)

project(exec)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-ggdb3 -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/../src/")
set(HEADER_DIR "${PROJECT_SOURCE_DIR}/../include/")
set(EXEC_DIR "${PROJECT_SOURCE_DIR}/../bin/apps/")

file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.c")
file(GLOB_RECURSE HEADER_FILES "${HEADER_DIR}/*.h")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXEC_DIR})
