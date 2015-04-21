#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <memory>
#include <vector>
#include <string>
//#include "Typedefs.h"
#include "Command.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class CdCommand:public Command
{
public:
    CdCommand(v_Iterator begin,v_Iterator end);
    
    void execute();
    
    ~CdCommand();
private:
    std::string directory;
};
#endif