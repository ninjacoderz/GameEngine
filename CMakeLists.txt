cmake_minimum_required(VERSION 3.23)

project(
        Asteroid
        VERSION 1.0
        DESCRIPTION "Asteroid"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

set(
        CMAKE_LIBRARY_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

add_executable(Asteroid
        Main.cpp
        Game.cpp
        Actor.cpp
        Asteroid.cpp
        CircleComponent.cpp
        Component.cpp
        InputComponent.cpp
        Laser.cpp
        Math.cpp
        MoveComponent.cpp
        Random.cpp
        Ship.cpp
        SpriteComponent.cpp
        VertexArray.cpp
        Shader.cpp
        Texture.cpp
)
set(SDLTTF_VENDORED ON)
set(VENDOR_DIR "${PROJECT_SOURCE_DIR}/vendor")

target_include_directories(Asteroid
        PRIVATE ${PROJECT_SOURCE_DIR}/src
        PRIVATE ${VENDOR_DIR}/glew/include
        PRIVATE ${VENDOR_DIR}/SOIL/includes
)

if(APPLE)
  set_target_properties(Asteroid PROPERTIES
          INSTALL_RPATH "@executable_path;@loader_path"
          BUILD_WITH_INSTALL_RPATH TRUE
          MACOSX_RPATH TRUE
  )
elseif(UNIX)
  set_target_properties(Asteroid PROPERTIES
          INSTALL_RPATH "$ORIGIN"
          BUILD_WITH_INSTALL_RPATH TRUE
  )
endif()
if (APPLE)
  find_library(COREFOUNDATION CoreFoundation)
endif()
add_subdirectory(${VENDOR_DIR}/SDL)
add_subdirectory(${VENDOR_DIR}/SDL_image)
add_subdirectory(${VENDOR_DIR}/SDL_ttf)
add_subdirectory(${VENDOR_DIR}/SOIL)
add_subdirectory(${VENDOR_DIR}/glew/build/cmake)

target_link_libraries(Asteroid
        SDL3::SDL3
        SDL3_image::SDL3_image
        glew_s
        soil
        ${COREFOUNDATION}
)