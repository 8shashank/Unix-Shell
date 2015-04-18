//
//  File.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/12/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#ifndef ___81Project__File__
#define ___81Project__File__

#include <iostream>
#include <vector>
#include "Typedefs.h"

class StartProcessCommand{
    
public:
    StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess);
    
    void execute();
    
private:
    std::string processName;
    std::vector<std::string> parsedargs;
    bool bg;
    bool autorec;
    
};

#include "StartProcessCommand.cpp"
#endif /* defined(___81Project__File__) */
