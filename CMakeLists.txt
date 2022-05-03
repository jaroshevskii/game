cmake_minimum_required(VERSION 3.0.0)

project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/sources/Main.cpp
  ${PROJECT_SOURCE_DIR}/sources/Game.cpp
  ${PROJECT_SOURCE_DIR}/sources/Window.cpp
  ${PROJECT_SOURCE_DIR}/sources/Hero.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} raylib)