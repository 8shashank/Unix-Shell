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
Parser();
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
#include "Parser.cpp"
#endif