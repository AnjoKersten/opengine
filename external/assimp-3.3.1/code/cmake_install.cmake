# Install script for directory: /Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/mathijs/HDMS DRIVE/opengine/external/lib/libassimp.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/anim.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/ai_assert.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/camera.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/color4.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/color4.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/config.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/defs.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Defines.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/cfileio.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/light.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/material.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/material.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/matrix3x3.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/matrix3x3.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/matrix4x4.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/matrix4x4.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/mesh.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/pbrmaterial.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/postprocess.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/quaternion.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/quaternion.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/scene.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/metadata.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/texture.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/types.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/vector2.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/vector2.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/vector3.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/vector3.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/version.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/cimport.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/importerdesc.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Importer.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/DefaultLogger.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/ProgressHandler.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/IOStream.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/IOSystem.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Logger.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/LogStream.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/NullLogger.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/cexport.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Exporter.hpp"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/DefaultIOStream.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/DefaultIOSystem.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SceneCombiner.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/fast_atof.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/qnan.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/BaseImporter.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Hash.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/MemoryIOWrapper.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/ParsingUtils.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/StreamReader.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/StreamWriter.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/StringComparison.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/StringUtils.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SGSpatialSort.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/GenericProperty.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SpatialSort.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SkeletonMeshBuilder.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SmoothingGroups.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/SmoothingGroups.inl"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/StandardShapes.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/RemoveComments.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Subdivision.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Vertex.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/LineSplitter.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/TinyFormatter.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Profiler.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/LogAux.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Bitmap.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/XMLTools.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/IOStreamBuffer.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/CreateAnimMesh.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/irrXMLWrapper.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/BlobIOSystem.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/MathFunctions.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Macros.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Exceptional.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Compiler/pushpack1.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Compiler/poppack1.h"
    "/Users/mathijs/HDMS DRIVE/opengine/external/assimp-3.3.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

