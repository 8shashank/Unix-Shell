<<<<<<< HEAD
//
//  Process.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/12/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#ifndef ___81Project__Process__
#define ___81Project__Process__

#include <iostream>
#include <signal.h>

class Process{
    
public:
    Process(std::string input, int rec, int foreground, int pid);
    Process(const Process& other);
    std::string get_state();
    void set_state();
    void set_signal();
    int get_signal();
    
private:
    std::string userinput;
    int autorec;
    int foreground;
    std::string state;
    int signal;
    int pid;
};


#endif /* defined(___81Project__Process__) */
=======
class Process{
 private:
  std::string state;
  int pid;
};
>>>>>>> 6363c0a4fbc5a4de7d9e19263235ae26ade941c0
