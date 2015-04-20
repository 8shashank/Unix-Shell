#ifndef COMMAND_H
#define COMMAND_H


class Command{
    Command();

    virtual ~Command();

    virtual void execute();
};

#endif