cmake_minimum_required(VERSION 3.4...3.27)

project(Pong LANGUAGES CXX)

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)

set(HodEngine_DIR E:/HodEngine)
include(${HodEngine_DIR}/CMake/Global.cmake)
include(${HodEngine_DIR}/CMake/FindHodEngine.cmake)
FindHodEngine()

file(GLOB_RECURSE Srcs
	"${PROJECT_SOURCE_DIR}/Sources/*.cpp"
	"${PROJECT_SOURCE_DIR}/Sources/*.hpp"
	"${PROJECT_SOURCE_DIR}/Sources/*.inl"
	"${PROJECT_SOURCE_DIR}/Sources/*.h"
)

file(GLOB_RECURSE Includes
	"${PROJECT_SOURCE_DIR}/Sources/*.hpp"
	"${PROJECT_SOURCE_DIR}/Sources/*.inl"
	"${PROJECT_SOURCE_DIR}/Sources/*.h"
)

assign_source_group(${Srcs}) # for VS

if (APPLE)
	add_library(Pong SHARED ${Srcs} ${Includes})
	target_include_directories(Pong PRIVATE ${PROJECT_SOURCE_DIR})
else()
	add_library(Pong SHARED ${Srcs} ${Includes})
	set_property(TARGET Pong PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

	#set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT HodApplication)
endif()

target_include_directories(Pong PUBLIC
	${PROJECT_SOURCE_DIR}/Sources
	${HodEngine_INCLUDE_DIRS}
)

target_link_libraries(Pong
	${HodEngine_CORE_LIBRARY}
	${HodEngine_WINDOW_LIBRARY}
	${HodEngine_RENDERER_LIBRARY}
	${HodEngine_INPUT_LIBRARY}
	${HodEngine_PHYSICS_LIBRARY}
	${HodEngine_GAME_LIBRARY}
	${HodEngine_IMGUI_LIBRARY}
	${HodEngine_EDITOR_LIBRARY}
	${HodEngine_AUDIO_LIBRARY}
	${HodEngine_APPLICATION_LIBRARY}
	${HodEngine_HOD_APPLICATION_LIBRARY}
)

target_compile_definitions(Pong PUBLIC ${PLATFORM_DEFINE} ${RENDERER_DEFINE})
target_compile_definitions(Pong PRIVATE PONG_EXPORT)

