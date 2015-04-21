#include "Process.h"

Process::Process(std::string pName, std::vector<std::string> args, bool bg_, bool autorec_):
processName(pName),parsedArgs(args),bg(bg_),autorec(autorec_),signal(-1),state("Running"){};

std::string Process::get_state(){
	return state;
}

/*
Process::Process(Process &p):
processName(p.processName),parsedArgs(p.parsedArgs),bg(p.bg),autorec(p.autorec),signal(p.signal),state(p.state)
{}*/


void Process::set_state(std::string state_){
	state=state_;
}

int Process::get_signal(){
	return signal;
}

void Process::set_signal(int sig){
	signal=sig;
}

std::string Process::get_name(){
    return processName;
}

std::vector<std::string> Process::get_args(){
    return parsedArgs;
}

bool Process::isAutoRecovery(){
	return autorec;
}

bool Process::isBg(){
    return bg;
}
