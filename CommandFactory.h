#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Typedefs.h"
#include <iostream>
#include <string>
#include "Command.h"
#include "Parser.cpp"
#include "Shell.h"

class CommandFactory{
    
public:
    CommandFactory();
    
    Command *makeCommand(std::vector<std::string> &args);
    
  
};

#endif
