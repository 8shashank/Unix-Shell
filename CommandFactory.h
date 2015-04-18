//
//  CommandFactory.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/14/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#ifndef ___81Project__CommandFactory__
#define ___81Project__CommandFactory__

#include <iostream>
#include <string>
#include "Command.h"
#include "Parser.h"
#include "Shell.h"

class CommandFactory{
    
public:
    CommandFactory();
    
    static Command makeCommand(std::string inp);
    
    ~CommandFactory();
    
private:
};


#endif /* defined(___81Project__CommandFactory__) */
