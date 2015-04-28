#ifndef SHOW_PROCESS_COMMAND_H
#define SHOW_PROCESS_COMMAND_H

#include <memory>
#include <vector>
#include <string>
#include "Command.h"
#include "Process.h"
#include "Shell.h"

typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class ShowProcessCommand:public Command
{
public:
    /*
    @brief: Constructor for the ShowProcessCommand.
    Shows all the previous commands that have been run
    @params: Iterators to the beginning and end of arguments list
    */
    ShowProcessCommand(v_Iterator begin,v_Iterator end);
    
    /*
    @brief: Executes the ShowProcessCommand, showing the 
    process map in a readable format
    */
    void execute();

    /*
    @brief: Prints an individual command by its pid and Process object
    */
    void printProcessInfo(int pid,Process &proc);
    
    /*
    @brief: Destructor for the ShowProcessCommand
    */
    ~ShowProcessCommand();

 private:
     //Holds a vector of pids to display information about
 	std::vector<int> pids;
};
#endif