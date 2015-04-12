#include <unistd.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <linux/limits.h>
#include "Shell.h"



int main(){
	//get current working directory
    std::string cur=getCurrentDirectory();
	Shell shell(cur);
	shell.loop();
}
