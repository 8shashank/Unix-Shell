cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g")
add_executable (mainClass Process.cpp Parser.cpp Command.cpp CommandFactory.cpp Shell.cpp StartProcessCommand.cpp ShowProcessCommand.cpp CdCommand.cpp mainClass.cpp Exceptions.cpp)