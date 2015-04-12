#ifndef SHELL_H
#define SHELL_H
#include <unordered_map>
#include <iostream>
#include "Process.h"

/*Singleton class that holds the Shell */
class Shell{
public:
	static Shell *instance();

	void loop();

	static std::string getCurrentDirectory();
private:
	Shell();
	Shell(Shell &s)=delete;
	void operator=(Shell &s)=delete;

private:
	static Shell *instance;

 private:
  	std::string currDir;
  	std::unordered_map<int,Process> processMap;

};
#include "Shell.cpp"

#endif
