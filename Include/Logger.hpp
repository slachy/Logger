#pragma once

#include <string>
#include <fstream>
#include <type_traits>
#include <tuple>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "LogLevel.hpp"

template <template <class> class  WritePolicy>
class Logger : public WritePolicy<std::string>
{
public:
	template <LogLevel Level>
	void log(std::string str)
	{
		str = logLevelToStr<Level>() + str;
		this->write(str);
	}
};


