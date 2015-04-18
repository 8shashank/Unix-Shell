#ifndef START_PROCESS_COMMAND
#define START_PROCESS_COMMAND

#include "Typedefs.h"
#include <sys/types.h>
#include <sys/wait.h>

class StartProcessCommand{
    
public:
    StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess);
    
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
