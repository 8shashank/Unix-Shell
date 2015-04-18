#ifndef START_PROCESS_COMMAND
#define START_PROCESS_COMMAND

#include "Typedefs.h"

class StartProcessCommand{
    
public:
    StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess);
    
    void execute();
    
private:
    std::string processName;
    std::vector<std::string> parsedargs;
    bool bg;
    bool autorec;
};

#include "StartProcessCommand.cpp"
#endif