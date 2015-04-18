CommandFactory::CommandFactory(){};

Command* makeCommand(str_vect_itr begin,str_vect_itr end){
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
	}

	if (*begin=="cd"){
		return new CdCommand(begin,end);
	}
	else if (begin=="echo"){
		return new EchoCommand(begin,end);
	}
	else{
		return new StartProcessCommand(begin,end);
	}
}
