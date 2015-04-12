Shell *Shell::instance_=nullptr;

Shell::~Shell(){

}

std::string getCurrentDirectory(){
    char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) == NULL){
       throw std::runtime_error ("Can't get current working directory.");
    }
	return std::string(cwd);
}

Shell *Shell::instance(){
    if (instance_==nullptr){
        instance_=new Shell();
    }
    return instance_;
}

void Shell::loop(){

}

Shell::Shell(std::string dir):currDir(dir){}
