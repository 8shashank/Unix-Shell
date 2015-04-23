#include "Shell.h"
#include "Exceptions.h"

Shell *Shell::instance_=nullptr;

Shell::~Shell(){

}

std::string Shell::getCurrentDirectory(){
	return currDir;
}


void Shell::changeCurrentDirectory(std::string fname){
	if (fname.length()>PATH_MAX-1){
		throw std::runtime_error("Path is longer than maximum allowed size.");
	}

	char path[PATH_MAX];
	strncpy(path, fname.c_str(), PATH_MAX - 1);

	int ret=chdir(path);
	if (ret==0){
		currDir=fname;
	}
	else{
		throw std::runtime_error("Could not change directory, received error "+ret);
	}
	setCurrentDirectory();
}

void Shell::addProcess(int pid,std::shared_ptr<Process> process){
	processMap.emplace(int(pid),process);
}

std::unordered_map<int,std::shared_ptr<Process>> &Shell::getProcesses(){
	return processMap;
}

std::shared_ptr<Process> Shell::getProcess(int pid){
    return processMap[pid];
}

/*Retrieve the value of current directory from OS and store it */
void Shell::setCurrentDirectory(){
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) == NULL){
       throw std::runtime_error ("Can't get current working directory.");
    }
    currDir=std::string(cwd);
}

Shell* Shell::instance(){
    if (instance_==nullptr){
        instance_=new Shell();
    }
    return instance_;
}

Shell::Shell(){
	factory=new CommandFactory();
	setCurrentDirectory();
}

void Shell::loop(){
	Parser p;
	std::string input;
	std::string n;
	std::vector<std::string> args;
	std::cout<<getCurrentDirectory()<<"#: ";
	std::getline (std::cin,input);
	bool skip=false;
	while (input!="exit"){
		try{
			args=p.parse(input);
		}
		catch (Exceptions::ParserException e){
			std::cout<<e.what()<<std::endl;
			skip=true;
		}

		if (!skip && input.length()!=0){
			Command *cmd=factory->makeCommand(args.begin(),args.end());
			cmd->execute();
		}

		std::cout<<getCurrentDirectory()<<"#: ";
		std::cin.clear();
		std::getline (std::cin,input);
		skip=false;
	}
};
