#include "CommandFactory.h"

CommandFactory::CommandFactory(){};

Command *CommandFactory::makeCommand(v_Iterator begin,v_Iterator end){
	bool backgroundProcess=false,autorecovery=false;
	/*
	for(auto i=begin;i!=end;i++){
		if (*i==">" || *i=="<"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			RedirectionCommand cmd(left,right);
			return cmd;
		}
		else if (*i=="|"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			PipeCommand(left,right) cmd;
			return cmd;
		}
		else if (*i=="&"){
			backgroundProcess=true;
		}
		else if (*i=="--autorecovery"){
			autorecovery=true;
		}
	}*/

	if (*begin=="cd"){
		 Command* cmd=new CdCommand(begin,end);
		 return cmd;
	}
	else if (*begin=="ps"){
		Command* cmd=new ShowProcessCommand(begin,end);
		return cmd;
	}
	else{
		Command* cmd= new StartProcessCommand(begin,end,backgroundProcess,autorecovery);
		return cmd;
	}
};
