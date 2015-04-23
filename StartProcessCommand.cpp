#include "StartProcessCommand.h"
#include <errno.h>
StartProcessCommand::StartProcessCommand(v_Iterator begin,v_Iterator end,bool backgroundProcess,bool autorecovery):bg(backgroundProcess),autorec(autorecovery){
  processName=*begin;
  v_Iterator iter=begin;
  while(iter!=end){
    if (*iter=="&"){
      //std::cout<<"Bg is true"<<std::endl;
      bg=true;
    }
    else if (*iter=="--autorecovery"){
      autorec=true;
    }
    else{
      std::cout<<"I'm pushing"<<*iter;
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
  if (sigprocmask(SIG_BLOCK,&mask,NULL)==-1){
    std::cout<<"Blocking SIGCHLD failed"<<std::endl;
  }
  std::cout<<"About to fork process "<<processName<< " as " << getpid() <<"\n";
  int rc=fork();
  if (rc<0){
    fprintf(stderr,"Fork failed\n");
  }else if (rc==0){
    int size=parsedargs.size();
    std::cerr<<"SIZE:"<<size<<"\n";
    char *myargs[size+1];
    std::cerr<<"Child's pid is:"<<getpid();
    for (int i=0;i<size;i++){
      //std::cerr<<parsedargs[i];
      myargs[i]=const_cast<char*>(parsedargs[i].c_str());
    }
    std::cerr<<"\n";
    myargs[size]=NULL;
    char* pName=const_cast<char*>(processName.c_str());
    //myargs[0]=pName;
    //std::cerr<<"About to execute process ";
    //std::cerr<<pName;
    execvp(pName,myargs);
    std::cerr << "exec failed\n";
    std::quick_exit(-1);
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
  //bool exitedCorrectly=false;
  // while(!exitedCorrectly){ //i got ride of the while loop.seems like it is
  //calling a blocking waitpid here for foreground
  // process so should not need a while loop

  int status;
  int wc=waitpid(rc,&status,0);
  if (wc<0){
    std::cout<<"Waitpid did not return properly";
    return;
  }

  std::shared_ptr<Process> deadProcess;
  Shell *s = Shell::instance();
  deadProcess = s->getProcess(rc);
  deadProcess->set_signal(WTERMSIG(status));
  deadProcess->set_state("Exited");
  if (WIFEXITED(status)){
    if (WEXITSTATUS(status)==0){
      // exitedCorrectly=true;
      std::cout<<"foreground process exited correctly."<<"\n";
    }
    else{
      std::cout<<"exit status: "+WEXITSTATUS(status)<<"\n";
      std::cout<<"foreground process exited incorrectly."<<"\n";

      //throw std::runtime_error("Child did not exit successfully.");
    }
  }else if (WIFSIGNALED(status)){
    int terminated_sig = WTERMSIG(status);
    deadProcess->set_signal(terminated_sig);
    std::cout<<"Child process terminated by signal "+WTERMSIG(status);
    //throw std::runtime_error("Child process terminated by signal "+WTERMSIG(status));
  }
  //If none of above true, child was either stopped or continued. Wait for termination.
  // }
}

void StartProcessCommand::sig_handler(int sig){
  int pid = 0;
  int status;
  std::cout<<"I'm in signal handler"<<std::endl;
  do{
    pid = waitpid(-1,&status,WNOHANG);
    //std::cout<<pid<<std::endl;
    if (pid==-1){
      std::cout<<getpid() << sig << ' ' << strerror(errno)<<std::endl;
      return;
    }
    if (pid != -1 && pid!=0){

      std::shared_ptr<Process> deadProcess;
      Shell *s = Shell::instance();
      deadProcess = s->getProcess(pid);
      deadProcess->set_state("Exited");
      int terminated_sig = WTERMSIG(status);
      deadProcess->set_signal(terminated_sig);

      if (deadProcess->isBg()){
        if (WIFEXITED(status)){

          if (WEXITSTATUS(status)==0){
            std::cout<<"Child "<<pid<<" exited successfully"<<std::endl;
          }
          else{
            std::cout<<"Child "<<pid<<" did not exit successfully."<<std::endl;
          }
        }
        else if (WIFSIGNALED(status)){
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