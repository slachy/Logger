#pragma once

#include <string>
#include <fstream>
#include <type_traits>
#include <tuple>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "LogLevel.hpp"
#include "FileLogPolicy.hpp"
#include "ThreadSafePolicy.hpp"
#include "SingleThread.hpp"

template <class  WritePolicy, class ThreadingModel = SingleThread>
class Logger : public WritePolicy, ThreadingModel
{
public:
	template <LogLevel Level>
	void log(std::string str)
	{
		str = logLevelToStr<Level>() + str;
		this->lock();
		this->write(str);
		this->unlock();
	}

	bool changeFile(std::string filename)
	{
		FileWriter& myWriter = *this;
		myWriter.close();
		myWriter.open(filename);
	}
};


