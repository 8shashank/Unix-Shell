#include "Parser.h"

Parser::Parser():
	delim(' ')
	,pipeOperator('|')
	,redirectOutputOperator('>')
	,redirectInputOperator('<')
	,escapeCharacter('\\')
	,singleQuoteCharacter('\'')
	,doubleQuoteCharacter('"')
	,backgroundJobOperator('&')
{

};

std::vector<std::string> Parser::parse(std::string str){
	std::vector<std::string> args;
	std::string curr="";

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
				//escape if required to continue
				//quote
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
			if (c==escapeCharacter){
				//ignore escape character
			}
			else if (c==singleQuoteCharacter || c==doubleQuoteCharacter){
				if (insideQuotes){
					if (c==quote){
						insideQuotes=false;
					}
					else{
						curr+=c;
					}
				}
				else {
					quote=c;
					insideQuotes=true;
				}
			}
			else if (c==pipeOperator || c==redirectInputOperator || c==redirectInputOperator
			|| c==backgroundJobOperator){
			        if (curr.length()!=0){
					args.push_back(std::move(curr));
					curr="";
				}
				args.push_back(std::string(1,c));
			}
			else if (c==delim && !insideQuotes){
				if (curr.length()!=0 ){
					args.push_back(std::move(curr));
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
		throw Exceptions::ParserException("Malformed input: Last character cannot act as escape character");
	}
	if (insideQuotes){
		throw Exceptions::ParserException("Malformed input: Quotes not closed");
	}
	if (curr.length()!=0){
		args.push_back(std::move(curr));
	}
	return args;
};