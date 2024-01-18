CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
project(SimpleFactory)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(Inc)

FILE(GLOB SOURCE_FILES Src/*.cpp)

foreach (source_file ${SOURCE_FILES})
    set_source_files_properties(${source_file} PROPERTIES COMPILE_FLAGS "-save-temps")
endforeach ()

add_executable(SimpleFactory ${SOURCE_FILES})