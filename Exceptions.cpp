#include <exception>
namespace Shell{
class ParserException : public std::exception
{
public:
ParserException(const std::string& message);
virtual char const * what() const throw();

private:
	std::string msg;
};

ParserException::ParserException(const std::string& message):msg(message){};

char const *ParserException::what() const throw(){ return msg.c_str(); }
}



