Shell *Shell::instance_=nullptr;

Shell::~Shell(){

}

std::string getCurrentDirectory(){
	return currDir;
}

void changeCurrentDirectory(std::string fname){
	if (fname.length>PATH_MAX){
		throw std::runtime_error("Path is longer than maximum allowed size.");
	}

	const char path[PATH_MAX];
	strncpy(fname, path.c_str(), sizeof(fname));

	int ret=chdir(path);
	if (ret==0){
		currDir=fname;
	}
	else{
		throw std::runtime_error("Could not change directory, received error "+ret);
	}
	setCurrentDirectory();
}

/*Retrieve the value of current directory from OS and store it */
std::string setCurrentDirectory(){
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) == NULL){
       throw std::runtime_error ("Can't get current working directory.");
    }
    currDir=std::string(cwd);
}

Shell *Shell::instance(){
    if (instance_==nullptr){
        instance_=new Shell();
    }
    return instance_;
}

void Shell::loop(){
	Parser p;
	std::string input;
	std::string n;
	std::vector<std::string> args;
	std::cout>>"#: ";
	std::getline (std::cin,input);
	while (input!="exit"){
		args=p.parse(input);

		Command cmd=factory.makeCommand(args);
		cmd.execute();

		std::cout>>"#: ";

		std::cin.clear();
		std::getline (std::cin,input);
	}
};

Shell::Shell():factory(){
	setCurrentDirectory();
}