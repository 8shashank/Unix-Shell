cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g")
add_executable (mainClass mainClass.cpp Shell.cpp Process.cpp StartProcessCommand.cpp PipeCommand.cpp Parser.cpp Exceptions.cpp CommandFactory.cpp CdCommand.cpp)
target_link_libraries (mainClass boost_program_options)
