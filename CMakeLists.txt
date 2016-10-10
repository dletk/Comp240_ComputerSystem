cmake_minimum_required(VERSION 3.6)
project(PersonalProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CTutorial/bookCProgrammingLang/chapter5/createSubstring.c)
#Update the name of the file you want to build after the SOURCE_FILES above
add_executable(PersonalProject ${SOURCE_FILES})