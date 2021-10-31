cmake_minimum_required(VERSION 3.0)

#project(Ex3)
project(Ex3 LANGUAGES CXX)

#set the required CPP standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set CXX flags for the compiler to be very strict
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic")

## Enable Clang sanitizer for memory warnings during Debug builds
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
  # -fsanitize=thread")
  # -fsanitize=memory")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUGS} -fno-omit-frame-pointer -fsanitize=address")
  # -fsanitize=memory")
  # -fsanitize=thread")
endif()

# Define our library name
set(MY_LIBRARY "Matrix")

file(GLOB MY_LIBRARY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp")
set(MY_LIBRARY_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

# build the library
if(MY_LIBRARY_SOURCES)
  message(STATUS "Building shared library")
  add_library(${MY_LIBRARY} SHARED ${MY_LIBRARY_SOURCES})
  target_include_directories(${MY_LIBRARY} PUBLIC "${MY_LIBRARY_INCLUDE_DIRS}")
else(MY_LIBRARY_SOURCES)
  message(STATUS "Building header-only library")
  add_library(${MY_LIBRARY} INTERFACE)
  target_include_directories(${MY_LIBRARY} INTERFACE "${MY_LIBRARY_INCLUDE_DIRS}")
endif(MY_LIBRARY_SOURCES)

set(MY_EXEC_FILES "")
#list(APPEND MY_EXEC_FILES "Basic")
list(APPEND MY_EXEC_FILES "LinAlgEx")

foreach(MY_EXEC_FILES ${MY_EXEC_FILES})
  add_executable(${MY_EXEC_FILES} ${MY_EXEC_FILES}.cpp)
  target_include_directories(${MY_EXEC_FILES} PUBLIC "${MY_LIBRARY_INCLUDE_DIRS}")
  target_link_libraries(${MY_EXEC_FILES} PRIVATE ${MY_LIBRARY})
endforeach(MY_EXEC_FILES ${MY_EXEC_FILES})
