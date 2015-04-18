#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <string>
#include "Shell.h"
#include "Command.h"

class CdCommand:public Command

{
public:
    CdCommand(string dir);
    
    void execute():
    
private:
    string directory;
};

#endif