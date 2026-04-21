# Install script for directory: /Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.2.3.1.dylib"
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.2.3.dylib"
      )
    foreach(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEWd.2.3.1.dylib"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEWd.2.3.dylib"
        )
      if(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        if(CMAKE_INSTALL_DO_STRIP)
          execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
        endif()
      endif()
    endforeach()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.2.3.1.dylib"
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.2.3.dylib"
      )
    foreach(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.1.dylib"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.dylib"
        )
      if(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        if(CMAKE_INSTALL_DO_STRIP)
          execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
        endif()
      endif()
    endforeach()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.2.3.1.dylib"
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.2.3.dylib"
      )
    foreach(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.1.dylib"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.dylib"
        )
      if(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        if(CMAKE_INSTALL_DO_STRIP)
          execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
        endif()
      endif()
    endforeach()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.2.3.1.dylib"
      "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.2.3.dylib"
      )
    foreach(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.1.dylib"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGLEW.2.3.dylib"
        )
      if(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        if(CMAKE_INSTALL_DO_STRIP)
          execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
        endif()
      endif()
    endforeach()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug/libGLEWd.dylib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release/libGLEW.dylib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel/libGLEW.dylib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo/libGLEW.dylib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/Debug/glewinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/Release/glewinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/MinSizeRel/glewinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/RelWithDebInfo/glewinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/glewinfo")
      endif()
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/glewinfo.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/glewinfo.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/glewinfo.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/glewinfo.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/Debug/visualinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Debug"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/Release/visualinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/Release"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/MinSizeRel/visualinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/MinSizeRel"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      endif()
    endif()
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/bin/RelWithDebInfo/visualinfo")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/lib/RelWithDebInfo"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/visualinfo")
      endif()
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/visualinfo.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/visualinfo.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/visualinfo.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/visualinfo.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/glew.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GL" TYPE FILE FILES
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/../../include/GL/wglew.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/../../include/GL/glew.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/../../include/GL/glxew.h"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/../../include/GL/eglew.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glew/glew-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glew/glew-targets.cmake"
         "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glew/glew-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/glew/glew-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/CMakeFiles/Export/7a894a12241bfddc41ca6be6d0e647bd/glew-targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/glew" TYPE FILE FILES
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/glew-config.cmake"
    "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/vendor/glew/build/cmake/CopyImportedTargetProperties.cmake"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/binhnguyenthanh/Documents/GameProgramming/SDL3/OpenGLEngine/build/vendor/glew/build/cmake/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
