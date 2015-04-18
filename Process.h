<<<<<<< HEAD
//
//  Process.h
//  281Project
//
//  Created by Arthur Yingpeng Chu on 4/12/15.
//  Copyright (c) 2015 Vanderbilt University. All rights reserved.
//

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <signal.h>

class Process{
    
public:
    Process(std::string pName, std::vector<std::string> args, bool bg_, bool autorec_);
    Process(const Process& other);
    std::string get_state();
    void set_state(std::string state);
    void set_signal(int sig);
    int get_signal();
    bool isBg();
    bool isAutoRecovery();
    
private:
    bool autorec;
    bool bg;
    std::string state;
     std::vector<std::string> parsedArgs;
    int signal;
};

#include "Process.cpp"
#endif