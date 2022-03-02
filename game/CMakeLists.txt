cmake_minimum_required(VERSION 3.1)

project(ray-casting-game)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/img)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


set(HEADERS
    include/player.hpp
)

set(SOURCES
    src/main.cpp
    src/player.cpp
)

add_executable(game 
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(game sfml-graphics sfml-audio)


