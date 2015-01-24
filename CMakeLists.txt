# Rogue CMake file
# by: Andy Moran
# Started 01-23-15

# version info
cmake_minimum_required ( VERSION 2.8 )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11" )

project ( Rogue )

find_library( NCURSES ncurses )

include_directories( include )

file( GLOB SOURCES src/*.cc )

add_executable( Rogue ${SOURCES} )

target_link_libraries( Rogue ${NCURSES} )

