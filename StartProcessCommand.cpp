

StartProcessCommand(v_Iterator begin,v_Iterator end,bool bg_):bg(false),autorec(false){
	processName=*begin;
	v_Iterator iter=begin+1;
	while(iter!=end){
		if (*iter=="&"){
			bg=true;
		}
		else if (*iter=="--autorecovery"){
			autorec=true;
		}
		else{
			parsedargs.push_back(*iter);
		}
		++iter;
	}
}

void StartProcessCommand::execute(){

//Use semaphore to make sure parent called first
	std::string semName=std::string("/sem")+processName;
	sem_t *sem = sem_open(semName, O_CREAT, 0644, 0); 

	int rc=fork();
        if (rc<0){
            fprintf(stderr,"Fork failed\n");
        }else if (rc==0){

        	sem_t *sem = sem_open(semName, 0);
        	sem_wait(sem);

        	int size=parsedargs.length();
            char *myargs[size+1];
            for (int i=0;i<size;i++){
            		myargs[i]=strdup(parsedargs[i]);
            }
            myargs[size]=NULL;
            execvp(strdup(processName),myargs);
        }
        else{
        	auto sp1=make_shared<Process>(processName,parsedargs,bg,autorec);
        	 Shell* s=Shell::instance()
        	 s->addProcess(rc,sp1);

        	 //Now child process can execute
        	sem_post(sem);
        	if (!bg){
            		CheckWait::waitForExit(rc);
            	}            
        }

}

void StartProcessCommand::waitForExit(int rc){
        bool exitedCorrectly=false;
        while(!exitedCorrectly){
            int status;
            int wc=waitpid(rc,&status,0);
            if (wc<0){
                throw std::runtime_error("Waitpid did not return properly");
            }
            if (WIFEXITED(status)){
                if (WEXITSTATUS(status)==0){
                    exitedCorrectly=true;
                }
                else{
                    throw std::runtime_error("Child did not exit successfully.");
                }
            }else if (WIFSIGNALED(status)){
                throw std::runtime_error("Child process terminated by signal "+WTERMSIG(status));
            }  
            //If none of above true, child was either stopped or continued. Wait for termination.
        }
    }