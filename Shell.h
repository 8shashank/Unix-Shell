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

	std::string getCurrentDirectory();

	void changeCurrentDirectory(std::string dir);
private:
	Shell();
	Shell(Shell &s)=delete;
	void operator=(Shell &s)=delete;
	std::string setCurrentDirectory();


private:
	static Shell *instance;

 private:
  	std::string currDir;
  	std::unordered_map<int,Process> processMap;

};
#include "Shell.cpp"

#endif
