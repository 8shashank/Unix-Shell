#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <signal.h>
#include <vector>

class Process{
  
public:
  /*
    @brief: Constructor for Process object
    @params: name of process, arguments that process takes,
    boolean for if it's run in background, and whether it should
    auto-recover if not killed by SIGSEGV or SIGINT
    */
  Process(std::string pName, std::vector<std::string> args, bool bg_, bool autorec_);

  /*
    @brief: Returns the state(running/dead) of the process
    @return: state as string
    */
  std::string get_state();

  /*
    @brief: Changes the state(running/dead) of the process
    @params: New state as string
    */
  void set_state(std::string state);

  /*
    @brief: Changes the signal used to kill process
    @params: New signal as int
    */
  void set_signal(int sig);

  /*
    @brief: Returns the signal used to kill process
    @return: signal as int
    */
  int get_signal();

  /*
    @brief: Returns the name of the process
    @return: name as string
    */
  std::string get_name();

  /*
    @brief: Returns the vector of arguments of the process
    @return: arguments as vector of strings
    */
  std::vector<std::string> get_args();

  /*
    @brief: Returns whether it is a background process or not
    @return: bool value
    */
  bool isBg();

  /*
    @brief: Returns whether it is a auto-recovery process or not.
    Auto-recovery processes restart unless killed by SIGINT or SIGSEGV
    @return: bool value
    */
  bool isAutoRecovery();
  
private:
  std::string processName;
  std::vector<std::string> parsedArgs;
  bool bg;
  bool autorec;
  int signal;
  std::string state;
};

#endif