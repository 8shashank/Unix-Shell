#ifndef COMMAND_H
#define COMMAND_H

class Command{
public:
    /*
    @brief: Constructor for the base class Command.
    Other commands inherit from this class.
    */
    Command();

    /*
    @brief: Virtual destructor for the Command class
    */
    virtual ~Command();

    /*
    @brief: Virtual execute function that other commands
    override.
    */
    virtual void execute();
};
#endif