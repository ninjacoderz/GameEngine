# Install script for directory: /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

set(CMAKE_BINARY_DIR "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build")

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/harfbuzz" TYPE FILE FILES
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-aat-layout.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-aat.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-blob.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-buffer.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-common.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-cplusplus.hh"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-deprecated.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-draw.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-face.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-font.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-map.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-color.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-deprecated.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-font.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-layout.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-math.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-meta.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-metrics.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-name.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-shape.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot-var.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ot.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-paint.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-set.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-shape-plan.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-shape.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-style.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-unicode.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-version.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-ft.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/SDL_ttf/external/harfbuzz/src/hb-coretext.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/SDL_ttf/external/harfbuzz-build/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
