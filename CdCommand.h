//
//  CdCommand.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/3/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#ifndef _81Project_CdCommand_h
#define _81Project_CdCommand_h

#include <string>
#include "Shell.h"
#include "Command.h"


class CdCommand:public Command

{
public:
    CdCommand(string dir);
    
    void execute():
    
private:
    string directory;
};

#endif