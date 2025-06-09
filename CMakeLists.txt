### ----------------------------------------------------------------------------------
### shared stuff
### ----------------------------------------------------------------------------------

### enforce version 3.20+
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 23)

project(lynx)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(lynx STATIC ${SOURCES})

target_compile_options(lynx PUBLIC
  -fno-exceptions
  -fno-rtti
)
