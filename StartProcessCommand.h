#ifndef START_PROCESS_COMMAND
#define START_PROCESS_COMMAND

#include <memory>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <vector>
#include "Command.h"
#include <unistd.h>
#include "Process.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class StartProcessCommand: public Command{

public:
  /*
  @brief: Constructor for the StartProcessCommand
  @params: Iterators to beginning and end of arguments list,
  bool values for if it is a background process and if it is in auto-recovery mode.
  In auto-recovery mode, process is restarted if not killed by SIGSEGV or SIGINT
  */
  StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess,bool autorecovery);

  /*
  @brief: Alternate constructor for the StartProcessCommand
  @params: takes a process name, arguments list as vector,
  and bool values for if it is a background process and if it is in auto-recovery mode.
  */
  StartProcessCommand(std::string processName_,std::vector<std::string> args,bool bg_,bool autorec_);

  /*
  @brief: Destructor for the StartProcessCommand
  */
  ~StartProcessCommand();

  /*
  @brief: Executes the StartProcessCommand, starting a process according to user passed parameters
  */
  void execute();

  /*
  @brief: Handles the SIGCHLD signal indicating child process is dead if it is background mode child.
  It also changes the state of the process in the process map.
  */
  void static sig_handler(int sig);

  /*
  @brief: Does a blocking wait for the child process to exit
  */
  void waitForExit(int rc);

private:
  //name of process
  std::string processName;

  //vector of parsed arguments
  std::vector<std::string> parsedargs;

  //boolean that's true if process run in background
  bool bg;

  //boolean that's true if process will auto-recover
  bool autorec;
};

#endif