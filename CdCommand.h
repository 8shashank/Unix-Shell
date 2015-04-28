#ifndef CD_COMMAND_H
#define CD_COMMAND_H

#include <memory>
#include <vector>
#include <string>
#include "Command.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class CdCommand:public Command
{
public:
    /*
    @brief: Constructor for the CdCommand
    @params: Iterators to the beginning and end of the arguments vector
    */
    CdCommand(v_Iterator begin,v_Iterator end);
    
    /*
    @brief: Executes the CdCommand, changing shell's directory
    */
    void execute();
    
    /*
    @brief: Destroys the CdCommand
    */
    ~CdCommand();
private:
    //Holds the directory name
    std::string directory;
};
#endif