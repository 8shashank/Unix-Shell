#include "Typedefs.h"
class CommandFactory{

    CommandFactory();

    Command *makeCommand(std::vector<std::string> &args);

    ~CommandFactory();
};