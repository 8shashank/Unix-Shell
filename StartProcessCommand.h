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
//#include "Typedefs.h"
#include "Process.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class StartProcessCommand: public Command{
    
public:
    StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess,bool autorecovery);
    StartProcessCommand(std::string processName_,std::vector<std::string> args,bool bg_,bool autorec_);
    ~StartProcessCommand();

    void setInputToPipe(int i);

    void setOutputToPipe(int o);
    
    void execute();
    
    void static sig_handler(int sig);
    void waitForExit(int rc);
    
private:
    std::string processName;
    std::vector<std::string> parsedargs;
    bool bg;
    bool autorec;
};

#endif