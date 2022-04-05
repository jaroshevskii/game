cmake_minimum_required(VERSION 3.5)

project(Game)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/sources/Main.cpp
  ${PROJECT_SOURCE_DIR}/sources/Game.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} raylib)