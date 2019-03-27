# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (OPEngine)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


# Compile external dependencies
add_subdirectory (external)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# Create a group for Visual Studio
	SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.8.4/
	external/glad/include/glad/
	external/assimp/include/

	# freetype
  ${CMAKE_SOURCE_DIR}/external/freetype-2.8.1/include
  ${CMAKE_SOURCE_DIR}/external/freetype-2.8.1/src
	
	.
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLAD
	freetype
)

#################
### FREETYPE2 ###
#################

set (FREETYPE2_INCLUDE_DIR
  ${CMAKE_CURRENT_SOURCE_DIR}/external/freetype-2.8.1
)

add_subdirectory(
  external/freetype-2.8.1
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# src (libcommon.a)
add_library(src
    		src/Renderer/renderer.h
    		src/Renderer/renderer.cpp
		src/Renderer/shader.h
		src/Renderer/camera.h
		src/Maths/glm.h
		src/Model/model.h
		src/Model/mesh.h
		src/Texture/stb_image.cpp
		src/Texture/stb_image.h
		src/config.h
		src/Texture/Texture.cpp
		src/Texture/Texture.h
		src/Graphics/skybox.h
		src/Graphics/Color.h
		src/Graphics/color.cpp
		src/Graphics/light.h
		src/Graphics/light.cpp
		src/UI/UIText.h
		src/UI/UIText.cpp
		src/UI/UICollection.cpp
		src/UI/UICollection.h
		src/Texture/FontLoader.cpp
		src/Texture/FontLoader.h
		src/Core/input.h
		src/Core/input.cpp
		src/Renderer/actor.h
		src/Renderer/actor.cpp
		src/Maths/transform.h
		src/Core/core.h
		src/Core/core.cpp
)

# Engine
add_executable(engine
	engine/main.cpp
)
target_link_libraries(engine
	src
	${ALL_GRAPHICS_LIBS}
	assimp
)
# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY engine/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY src/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
