#include <iostream>
#include "Logger.hpp"

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

template void Logger::log<LogLevel::Info>(std::string);
template void Logger::log<LogLevel::Debug>(std::string);
template void Logger::log<LogLevel::Warning>(std::string);
template void Logger::log<LogLevel::Error>(std::string);

template <LogLevel Level>
void Logger::log(std::string str)
{
	std::string logLevelStr(logLevelToStr<Level>());
	if (file.is_open())
	{
	    file << logLevelStr << str << std::endl;
		return;
	}
	output << logLevelStr << str << std::endl;
}
