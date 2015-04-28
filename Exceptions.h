#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
namespace Exceptions{
class ParserException : public std::exception
{
public:
/*
@brief: ParserException constructor
@param: String message to show when thrown
*/
ParserException(const std::string& message);

/*
@brief: Prints the error message
*/
virtual char const * what() const throw();

private:
	//Error message to throw
	std::string msg;
};
};
#endif