<<<<<<< HEAD
#include "Typedefs.h"
class CommandFactory{
=======
//
//  CommandFactory.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/14/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//
>>>>>>> a8da12774c7eed55fc6b95641f84de6635639635

#ifndef ___81Project__CommandFactory__
#define ___81Project__CommandFactory__

<<<<<<< HEAD
    Command *makeCommand(std::vector<std::string> &args);
=======
#include <iostream>
#include <string>
#include "Command.h"
#include "Parser.h"
#include "Shell.h"
>>>>>>> a8da12774c7eed55fc6b95641f84de6635639635

class CommandFactory{
    
public:
    CommandFactory();
    
    static Command makeCommand(std::string inp);
    
    ~CommandFactory();
<<<<<<< HEAD
};
=======
    
private:
};


#endif /* defined(___81Project__CommandFactory__) */
>>>>>>> a8da12774c7eed55fc6b95641f84de6635639635
