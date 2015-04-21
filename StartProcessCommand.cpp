#include "StartProcessCommand.h"

StartProcessCommand::StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess,bool autorecovery):bg(backgroundProcess),autorec(autorecovery){
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

StartProcessCommand::StartProcessCommand(std::string processName_,std::vector<std::string> args,bool bg_,bool autorec_):parsedargs(args),bg(bg_),
autorec(autorec_),processName(processName_)
{
}

StartProcessCommand::~StartProcessCommand(){}

void StartProcessCommand::setInputToPipe(int i){}

void StartProcessCommand::setOutputToPipe(int o){}

void StartProcessCommand::execute(){    
    struct sigaction sig_a;
    sig_a.sa_handler = &StartProcessCommand::sig_handler;
    sigemptyset(&sig_a.sa_mask);
    sig_a.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    if (sigaction(SIGCHLD, &sig_a, 0) == -1) {
        std::cout<<"Signal handler failed."<<std::endl;
    }

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask,SIGCHLD);
    if (sigprocmask(SIG_SETMASK,&mask,NULL)==-1){
        std::cout<<"Blocking SIGCHLD failed"<<std::endl;
    }

        int rc=fork();
        if (rc<0){
            fprintf(stderr,"Fork failed\n");
        }else if (rc==0){
        	int size=parsedargs.size();
            char *myargs[size+1];
            for (int i=0;i<size;i++){
            		myargs[i]=const_cast<char*>(parsedargs[i].c_str());
            }
            myargs[size]=NULL;
            char* pName=const_cast<char*>(processName.c_str());
            execvp(pName,myargs);
        }
        else{
        	auto sp1=std::make_shared<Process>(processName,parsedargs,bg,autorec);
        	 Shell::instance()->addProcess(rc,sp1);
        if (sigprocmask(SIG_UNBLOCK,&mask,NULL)==-1){
        std::cout<<"Unblocking SIGCHLD failed"<<std::endl;
        }

        	if (!bg){
            		waitForExit(rc);
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

void StartProcessCommand::sig_handler(int sig){
    int pid = 0;
    int status;
    do{
        pid = waitpid(-1,&status,WNOHANG);
        if (pid != 0){
            
            std::shared_ptr<Process> deadProcess;
            Shell *s = Shell::instance();
            deadProcess = s->getProcess(pid);
            
            if (deadProcess->isBg()){
                if (WIFEXITED(status)){
                    deadProcess->set_state("Exited");
                    
                    if (WEXITSTATUS(status)==0){
                        std::cout<<"Child "<<pid<<" exited successfully"<<std::endl;
                    }
                    else{
                        std::cout<<"Child "<<pid<<" did not exit successfully."<<std::endl;
                    }
                }
                else if (WIFSIGNALED(status)){
                    int terminated_sig = WTERMSIG(status);
                    deadProcess->set_signal(terminated_sig);
                    std::cout<<"Child "<<pid<<" terminated by signal "<<terminated_sig<<std::endl;
                }
            
                if (deadProcess->isAutoRecovery()) {
                    StartProcessCommand RecCommand(deadProcess->get_name(),deadProcess->get_args(),deadProcess->isBg(),deadProcess->isAutoRecovery());
                    RecCommand.execute();
                }
            }
            
        }        
    }while(pid!=0);
}