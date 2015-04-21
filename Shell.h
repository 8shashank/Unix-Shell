#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdexcept>
#include <iostream>
#include <linux/limits.h>
#include <unordered_map>
#include <string>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <vector>
#include "Process.h"
#include "Parser.h"
#include "CommandFactory.h"

class Process;
class CommandFactory;
class Parser;
/*Singleton class that holds the Shell */
class Shell{
public:
	static Shell *instance();

	void loop();

	std::string getCurrentDirectory();

	void changeCurrentDirectory(std::string dir);

	void addProcess(int pid, std::shared_ptr<Process> process);
    	std::shared_ptr<Process> getProcess(int pid);
    
private:
	Shell();
	Shell(Shell &s)=delete;
	void operator=(Shell &s)=delete;
	void setCurrentDirectory();
	~Shell();


private:
	static Shell *instance_;

 private:
  	std::string currDir;
  	std::unordered_map<int,std::shared_ptr<Process>> processMap;
  	CommandFactory *factory;
  	//bool continue;
};

#endif