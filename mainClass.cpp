#include <unistd.h>
#include <string>
#include <stdexcept>
#include "Shell.h"

int main(){
	//get current working directory
	char* buf;
	getcwd(buf);
	if (buf==nullptr){
	  throw std::runtime_error("Cannot retrieve current working directory");
	}

	std::string currDir(buf);

	Shell shell(currDir);
	shell.start();
}
