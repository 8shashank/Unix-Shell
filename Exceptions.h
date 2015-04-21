#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
namespace Exceptions{
class ParserException : public std::exception
{
public:
ParserException(const std::string& message);
virtual char const * what() const throw();

private:
	std::string msg;
};
};
#endif