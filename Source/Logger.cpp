#include <iostream>
#include "Logger.hpp"

void Logger::log(std::string str)
{
	output << str << std::endl;
}
