#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <iostream>
#include <string>
#include "Typedefs.h"
#include "Command.h"
#include "CdCommand.h"
#include "StartProcessCommand.h"
#include "Parser.h"

class Shell;
class CdCommand;
class StartProcessCommand;
class CommandFactory{
    
public:
    CommandFactory();
    
    Command *makeCommand(std::vector<std::string>::iterator begin,std::vector<std::string>::iterator end);
    
  
};
#include "CommandFactory.cpp"
#endif
