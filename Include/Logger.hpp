#include <string>
#include <fstream>

class Logger
{
public:
	Logger(std::ostream& stream) : output(stream) {}
	Logger(std::string filename) : output(std::cout)
	{
		file.open(filename);
	}
	std::ostream& log(std::string);

private:
	std::ostream& output;
	std::ofstream file;
};
