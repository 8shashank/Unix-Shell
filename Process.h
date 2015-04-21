#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <signal.h>

class Process{
    
public:
    Process(std::string pName, std::vector<std::string> args, bool bg_, bool autorec_);
    //Process(const Process& other);
    std::string get_state();
    void set_state(std::string state);
    void set_signal(int sig);
    int get_signal();
    std::string get_name();
    std::vector<std::string> get_args();
    bool isBg();
    bool isAutoRecovery();
    
private:
    std::string processName;
    std::vector<std::string> parsedArgs;
    bool bg;
    bool autorec;
    int signal;
    std::string state;
};

#include "Process.cpp"
#endif