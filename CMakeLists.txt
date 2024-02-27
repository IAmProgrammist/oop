cmake_minimum_required(VERSION 3.5)

project(oop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Boost REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
else()
  message(STATUS "Boost NOT Found !")
endif(Boost_FOUND)

message("LIBRARY_ONLY=${LIBRARY_ONLY}")

add_subdirectory(src)

if (NOT LIBRARY_ONLY)
    enable_testing()
    add_subdirectory(test)
endif()
