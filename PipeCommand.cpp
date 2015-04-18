PipeCommand(Command left_,Command right_):left(left_),right(right_){
}

void execute(){
	 //int array of 2, create pipe, inside fork, use dup2 to replace stdout to input of pipe, 
	//inside second fork, set stdin using dup2 to other end of pipe
	left.execute();

	std::cout.rdbuf(origOutput);	//set cout back to original

	std::string rightInput=leftInput.str();
	right.execute();
}