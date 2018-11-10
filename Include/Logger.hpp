#include <string>

class Logger
{
public:
	Logger(std::ostream& stream) : output(stream) {}
	void log(std::string);

private:
	std::ostream& output;
};
