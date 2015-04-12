#ifndef SHELL_H
#define SHELL_H
#include <unordered_map>
#include <iostream>
#include "Process.h"
class Shell{
public:
  Shell(std::string dir);

  void start();

 private:
  std::string currDir;
  std::unordered_map<int,Process> processMap;

};
#include "Shell.cpp"

#endif
