CommandFactory::CommandFactory(){};

Command* makeCommand(str_vect_itr begin,str_vect_itr end){
	bool backgroundProcess=false,autorecovery=false;
	for(auto i=begin;i!=end;i++){
		if (*i==">" || *i=="<"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			return new RedirectionCommand(left,right);
		}
		else if (*i=="|"){
			Command left=makeCommand(begin,i-1);
			Command right=makeCommand(i+1,end);
			return new PipeCommand(left,right);
		}
		else if (*i=="&"){
			backgroundProcess=true;
		}
		else if (*i=="--autorecovery"){
			autorecovery=true;
		}
	}

	if (*begin=="cd"){
		return new CdCommand(begin,end);
	}
	else{
		return new StartProcessCommand(begin,end,backgroundProcess,autorecovery);
	}
};