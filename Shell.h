#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <linux/limits.h>
#include <unordered_map>
#include <string>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <vector>
#include "Process.h"
#include "Parser.h"
#include "CommandFactory.h"

class Process;
class CommandFactory;
class Parser;

/*
@brief: Singleton class that holds the Shell
@details: Shell currently supports background processes,
foreground processes, change directory command,
and auto-recovery mode.
 */
class Shell{
public:
  /*
  @brief: Returns a pointer to the instance of the Shell singleton
  @return: Shell pointer
  */
  static Shell *instance();

  /*
  @brief: Runs the main loop of the shell
  */
  void loop();

  /*
  @brief: Returns the current working directory of the shell
  @return: string
  */
  std::string getCurrentDirectory();

  /*
  @brief: Changes the current working directory of the shell
  @params: working directory as string
  */
  void changeCurrentDirectory(std::string dir);

  /*
  @brief: Adds a new process to the process map
  @params: pid of the process, shared pointer to the process
  */
  void addProcess(int pid, std::shared_ptr<Process> process);

  /*
  @brief: Returns a shared pointer to a process from the process map by its pid
  @params: pid
  @return: Process object
  */
  std::shared_ptr<Process> getProcess(int pid);

  /*
  @brief: Returns the process map
  @return: Map of <int,shared_ptr<Process>> values
  */
  std::unordered_map<int,std::shared_ptr<Process>> &getProcesses();

private:
  /*
  @brief: Private constructor for the shell
  */
  Shell();

  /*
  @brief: Inaccessible copy constructor for the shell
  */
  Shell(Shell &s)=delete;

  /*
  @brief: Inaccessible assignment operator for the shell
  */
  void operator=(Shell &s)=delete;

  /*
  @brief: Private method to obtain current directory from the OS and storing it
  */
  void setCurrentDirectory();

  /*
  @brief: Destructor for the Shell
  */
  ~Shell();


private:
  //Holds an instance to the Shell
  static Shell *instance_;

private:
  std::string currDir;
  std::unordered_map<int,std::shared_ptr<Process>> processMap;
  CommandFactory *factory;
};

#endif