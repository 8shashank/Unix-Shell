//
//  CdCommand.cpp
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/3/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#include "CdCommand.h"
#include <string>

CdCommand::CdCommand(std::string dir):directory(dir)
{
}

void CdCommand::execute(){
    Shell s;
    Shell* m = s.instance();     //get Shell singleton
    
    m->changeCurrentDirectory(directory);  //change current dir of main shell
}

