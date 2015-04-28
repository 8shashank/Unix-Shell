
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Exceptions.h"

class Parser{
public:
/*
@brief: Constructor for the Parser object
*/
Parser();

/*
@brief: Parses user input of string and returns a vector of arguments
@params: User input as string
@return: vector of arguments as string
*/
std::vector<std::string> parse(std::string);

private:
	char delim;
	char pipeOperator;
	char redirectOutputOperator;
	char redirectInputOperator;
	char escapeCharacter;
	char singleQuoteCharacter;
	char doubleQuoteCharacter;
	char backgroundJobOperator;
};
#endif