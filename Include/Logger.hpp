#include <string>
#include <fstream>

enum class LogLevel { Debug, Info, Warning, Error };

class ConsoleLogPolicy
{
protected:
	template <class T> friend class Logger;

	void write(const std::string& buffer)
	{
		std::cout << buffer;
	}
};

template <LogLevel Level>
std::string logLevelToStr()
{
    return std::string("Default log level implementation");
}
template <>
std::string logLevelToStr<LogLevel::Info>()
{
    return std::string("[INFO] ");
}

template <>
std::string logLevelToStr<LogLevel::Debug>()
{
    return std::string("[DEBUG] ");
}

template <>
std::string logLevelToStr<LogLevel::Warning>()
{
    return std::string("[WARNING] ");
}

template <>
std::string logLevelToStr<LogLevel::Error>()
{
    return std::string("[ERROR] ");
}

template <class Policy>
class Logger
{
public:
	Logger() {}

	template <LogLevel Level>
	void log(std::string str)
	{
		std::string logLevelStr;
		logLevelStr = logLevelToStr<Level>();
		Policy p;
		p.write(logLevelStr + str);
	}
};


