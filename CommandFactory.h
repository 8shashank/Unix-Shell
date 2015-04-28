#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Command.h"
#include "Shell.h"
#include "CdCommand.h"
#include "StartProcessCommand.h"
#include "ShowProcessCommand.h"
#include "Parser.h"

class Shell;
typedef std::vector<std::string> string_vector;
typedef std::vector<std::string>::iterator v_Iterator;
class CommandFactory{
  
public:
  /*
    @brief: Constructor for the CommandFactory object
    */
  CommandFactory();
  
  /*
    @brief: Makes a command based on user arguments and returns a pointer to it
    */
  Command *makeCommand(std::vector<std::string>::iterator begin,std::vector<std::string>::iterator end);

};
#endif
