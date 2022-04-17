cmake_minimum_required(VERSION 3.18.4)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(blind_nav_system LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory (test)
enable_testing ()
add_test (NAME MyTest COMMAND Test)

add_compile_options(-Wall -Wconversion -Wextra -pedantic)

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