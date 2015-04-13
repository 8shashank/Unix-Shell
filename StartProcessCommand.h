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

class StartProcessCommand{

public:
    StartProcessCommand(std::string input);
    
    
private:
    std::string userinput;
    std::vector<std::string> parsedargs;
    std::string func_name;
    int foreground;
    int autorec;
    
};

#endif /* defined(___81Project__File__) */
