#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build
  make -f /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build
  make -f /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build
  make -f /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build
  make -f /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/CMakeScripts/ReRunCMake.make
fi

