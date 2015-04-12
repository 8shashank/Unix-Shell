class Command{
    virtual Command(std::string args);

    virtual ~Command();

    virtual void execute();
}
