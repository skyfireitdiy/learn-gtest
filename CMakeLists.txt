cmake_minimum_required(VERSION 3.28)

project(learn-gtest)

function(add_gtest name files)
    add_executable(${name})
    file(GLOB sources ${files})
    target_sources(${name} PRIVATE ${sources} main.cpp)
    target_compile_options(${name} PRIVATE -std=c++23)
    target_link_libraries(${name} PRIVATE gtest gmock)
endfunction(add_gtest name f)

file(GLOB dir_list [0-9][0-9].*)

foreach(target_path ${dir_list})
    get_filename_component(target ${target_path} NAME)
    add_gtest(${target} ${target_path}/*.cpp)
endforeach(target_path ${dir_list})

