cmake_minimum_required(VERSION 3.18.4)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(blind_nav_system LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wconversion -Wextra -pedantic)

#get googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest__POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

find_package (Threads)

set(LIBSRC Lidar.cpp Servo.cpp Pwm.cpp)
set(LIBINCLUDE lidar.h servo.h pwm.h)

add_library(lidar
  STATIC
  ${LIBSRC}
  )

set_target_properties(lidar PROPERTIES
  POSITION_INDEPENDENT_CODE TRUE
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(lidar ${CMAKE_THREAD_LIBS_INIT} pigpio rt)

install(TARGETS lidar EXPORT lidar_targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_executable (blind-nav main.cpp)
target_link_libraries(blind-nav lidar)

add_executable(testRunner test.cpp)
target_link_libraries(testRunner lidar gtest_main gmock_main)