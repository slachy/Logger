#include <string>
#include <fstream>

enum class LogLevel { Debug, Info, Warning, Error };

class Logger
{
public:
	Logger(std::ostream& stream) : output(stream) {}
	Logger(std::string filename) : output(std::cout)
	{
		file.open(filename);
	}

	template <LogLevel Level>
	void log(std::string);

private:
	std::ostream& output;
	std::ofstream file;
};
