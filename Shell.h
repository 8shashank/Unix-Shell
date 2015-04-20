#ifndef SHELL_H
#define SHELL_H

#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Process.h"
#include "CommandFactory.h"
#include "Parser.cpp"


/*Singleton class that holds the Shell */
class Shell{
public:
	static Shell *instance();

	void loop();

	std::string getCurrentDirectory();

	void changeCurrentDirectory(std::string dir);

	void addProcess(int pid, Process process);
    Process& getProcess(int pid);
    
private:
	Shell();
	Shell(Shell &s)=delete;
	void operator=(Shell &s)=delete;
	void setCurrentDirectory();


private:
	static Shell *instance_;

 private:
  	std::string currDir;
  	std::unordered_map<int,shared_ptr<Process>> processMap;
  	CommandFactory factory;
  	//bool continue;
};

#endif
