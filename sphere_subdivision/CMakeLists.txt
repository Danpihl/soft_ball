cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(subdivision)

find_package(OpenCV REQUIRED )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

find_package(Boost 1.58.0 COMPONENTS filesystem system program_options)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(VTK_LEGACY_SILENT:BOOL=ON)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set (CMAKE_SKIP_RULE_DEPENDENCY TRUE)
set (CMAKE_CXX_STANDARD 11)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

set(CPP_FILES subdivisor.cpp subdivisor.h edge.h edge.cpp face.h face.cpp point.h point.cpp)

add_executable (subdivision main.cpp ${CPP_FILES})

target_link_libraries (subdivision ${OpenCV_LIBS} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${OpenCV_LIBS} ${Boost_LIBRARIES})