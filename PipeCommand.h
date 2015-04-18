class PipeCommand{
public:
	PipeCommand(Command left_,Command right_);
	void execute();
private:
	Command left;
	Command right;
}