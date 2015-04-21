#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <string>
#include "Typedefs.h"
#include "Command.h"

class Shell;
class CdCommand:public Command
{
public:
    CdCommand(v_Iterator begin,v_Iterator end);
    
    void execute();
    
    ~CdCommand();
private:
    std::string directory;
};
#include "CdCommand.cpp"
#endif