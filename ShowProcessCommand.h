#ifndef SHOW_PROCESS_COMMAND_H
#define SHOW_PROCESS_COMMAND_H

#include <memory>
#include <vector>
#include <string>
//#include "Typedefs.h"
#include "Command.h"
#include "Process.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class ShowProcessCommand:public Command
{
public:
    ShowProcessCommand(v_Iterator begin,v_Iterator end);
    
    void execute();

    void printProcessInfo(int pid,Process &proc);
    
    ~ShowProcessCommand();

 private:
 	std::vector<int> pids;
};
#endif