cmake_minimum_required(VERSION 3.5)

SET( SRC_FILES main.cc SafeQueue.cc SafeQueue.hh )
PROJECT( SafeQueue )

SET( CMAKE_CXX_STANDARD 11 )

ADD_EXECUTABLE( SafeQueue ${SRC_FILES} )

# TARGET_LINK_LIBRARIES( SafeQueue pthread )

