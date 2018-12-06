#pragma once

#include <string>

#include "LogLevel.hpp"
#include "FileWriter.hpp"
#include "ThreadSafe.hpp"
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


