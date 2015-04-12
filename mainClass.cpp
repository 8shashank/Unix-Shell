#include <unistd.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <linux/limits.h>
#include "Shell.h"

std::string getCurrentDirectory(){
    char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) == NULL){
       throw std::runtime_error ("Can't get current working directory.");
    }
	return std::string(cwd);
}

int main(){
	//get current working directory
    std::string cur=getCurrentDirectory();
	Shell shell(cur);
	shell.start();
}
