#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake
  /Applications/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.2.3.1.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.2.3.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake
  /Applications/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.2.3.1.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.2.3.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake
  /Applications/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.2.3.1.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.2.3.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake
  /Applications/CMake.app/Contents/bin/cmake -E cmake_symlink_library /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.2.3.1.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.2.3.dylib /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.dylib
fi

