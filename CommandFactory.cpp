<<<<<<< HEAD
CommandFactory::CommandFactory(){};

Command* makeCommand(str_vect_itr begin,str_vect_itr end){
	for(auto i=begin;i!=end;i++){
		if (*i==">" || *i=="<"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			return new RedirectionCommand(left,right);
		}
		else if (*i=="|"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			return new PipeCommand(left,right);
		}
	}

	if (*begin=="cd"){
		return new CdCommand(begin,end);
	}
	else if (begin=="echo"){
		return new EchoCommand(begin,end);
	}
	else{
		return new StartProcessCommand(begin,end);
	}
}
=======
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

>>>>>>> a8da12774c7eed55fc6b95641f84de6635639635
