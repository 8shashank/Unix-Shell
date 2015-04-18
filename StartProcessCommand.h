#ifndef START_PROCESS_COMMAND
#define START_PROCESS_COMMAND

#include "Typedefs.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>


class StartProcessCommand{
    
public:
    StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess);
    StartProcessCommand(std::string processName_,std::vector<std::string> args,bool bg_,bool autorec_);
    
    void execute();
    
    void sig_handler();
    
private:
    std::string processName;
    std::vector<std::string> parsedargs;
    bool bg;
    bool autorec;
};

#include "StartProcessCommand.cpp"
#endif
