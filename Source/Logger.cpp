#include <iostream>
#include "Logger.hpp"

std::ostream& Logger::log(std::string str)
{
	if (file.is_open())
	{
	    file << str << std::endl;
		return file;
	}
	output << str << std::endl;
	return output;
}
