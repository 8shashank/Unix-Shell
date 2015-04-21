#include "Exceptions.h"

Exceptions::ParserException::ParserException(const std::string& message):msg(message){};

char const * Exceptions::ParserException::what() const throw()
{ return msg.c_str(); };
