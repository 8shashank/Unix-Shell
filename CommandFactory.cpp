//
//  CommandFactory.cpp
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/14/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#include "CommandFactory.h"
#include <sstream>

CommandFactory::CommandFactory(){
    
}

static Command CommandFactory::makeCommand(std::string inp){
    Parser p();
    vector<std::string*> args = p(inp);
    
    std::string CommandName = *(args.at(0));
    Command *newCommand;
    
    if (CommandName == "cd") {
        std::string dir = *(args.at(1));
        newCommand = CdCommand(dir);
    }
    
    if (CommandName == "run") {
        //handle two cases: foreground and background
    }
    
    if (CommandName == "status") {
        //fill in as needed
    }
    
    
    
    
    
    
    return *newCommand;
}

