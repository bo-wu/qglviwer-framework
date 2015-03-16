cmake_minimum_required(VERSION 2.8)
project(viewer)

find_package(Qt4 REQUIRED QtGui QtOpenGL QtXml)
file(GLOB SOURCE src/*.cpp src/*.cc)
file(GLOB HEADER src/*.h src/*.hh)
file(GLOB UIS src/*.ui)

set(MYGL_LIB GLEW glut GLU GL qglviewer-qt4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wreturn-type -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -Wno-sign-compare")

add_definitions(${QT_DEFINITIONS})
include_directories(${QT_INCLUDES})
include(${QT_USE_FILE})
QT4_WRAP_UI(UI_HDRS ${UIS})
QT4_WRAP_CPP(MOC_HEADER ${HEADER})
include_directories(${CMAKE_BINARY_DIR})

add_executable(viewer ${HEADER} ${SOURCE} ${UI_HDRS} ${MOC_HEADER})
target_link_libraries(viewer ${QT_LIBRARIES} ${MYGL_LIB})
