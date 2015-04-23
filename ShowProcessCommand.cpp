#include "ShowProcessCommand.h"

ShowProcessCommand::ShowProcessCommand(v_Iterator begin,v_Iterator end)
{
	v_Iterator iter=++begin;
	while (iter!=end){
		int pid= atoi((*iter).c_str());
		pids.push_back(pid);
		++iter;
	}
}

void ShowProcessCommand::execute(){
    Shell* s=Shell::instance();
    std::unordered_map<int,std::shared_ptr<Process>> &processes=s->getProcesses(); 
    std::cout<<"PID\tStatus\tTerminated by"<<std::endl;
    if (pids.empty()){
    	for(auto iter=processes.begin();iter!=processes.end();iter++){
    		Process &proc=*(iter->second);
    		printProcessInfo(iter->first,proc);
    	}
    }
    else{
    	for(auto iter=pids.begin();iter!=pids.end();iter++){
    		if (processes.count(*iter)==1){
    			Process &proc=*(processes[*iter]);
    			printProcessInfo(*iter,proc);
    		}
    	}
  }
}

void ShowProcessCommand::printProcessInfo(int pid,Process &proc){
	std::cout<<pid<<"\t"<<proc.get_state();
    	if (proc.get_signal()!=-1){
    		std::cout<<"\t"<<proc.get_signal();
    	}
    	std::cout<<"\n";
}

ShowProcessCommand::~ShowProcessCommand(){}