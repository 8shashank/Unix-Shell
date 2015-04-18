class Parser{
public:
Parser();
std::vector<std::string*> parse(std::string);

private:
};

Parser::Parser(){
};

//Not exception safe yet. std::vector did not appear to 
// be copying std::strings on return(got segfault) so currently using pointers.

std::vector<std::string*> Parser::parse(std::string str){
	std::vector<std::string*> args;
	std::string curr="";
	char delim=' ';
	char prevChar='\0';
	char quote='\0';
	bool insideQuotes=false;
	bool escaped=false;

	for(char& c:str){
		//Handle escaped characters
		if (escaped){

			if (!insideQuotes || (c=='\\')){
				curr+=c;
			}

			else{
				//do not escape if different quote types
				//eg: "\'" returns \' not '
				if (quote==c){
					curr+=c;
				}
				else{
					curr+=quote+=c;
				}
			}
		}

		//Handle regular case
		else{
			if (c=='\\'){
				//ignore escape character
			}
			else if (c=='"' || c=='\''){
				insideQuotes=!insideQuotes;
				quote=c;
			}
			else if (c==delim && !insideQuotes){
				if (curr.length()!=0 ){
					args.push_back(new std::string(curr));
					curr="";
				}
			}
			else{
				curr+=c;
			}
		}

		escaped=((c=='\\') && !escaped);
	}
	if (escaped){
		throw ::ParserException("Last character cannot act as escape character");
	}
	if (insideQuotes){
		throw ::ParserException("Quotes not closed");
	}
	args.push_back(new std::string(curr));
	return args;
};