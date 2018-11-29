#pragma once

#include <iostream>
#include <string>
#include "ILoggerPolicy.hpp"

class RedErrorPolicy : public ILoggerPolicy
{
protected:
	template <class ... T> friend class Logger;

	void applyPolicy(std::string& buffer) override
	{
        std::string toReplace("[ERROR]");
		size_t pos = buffer.find(toReplace);
		std::string red("\033[0;31m");
		std::string noColor("\033[0m");
		buffer.replace(pos, toReplace.length(), red + "[ERROR]" + noColor);
	}
};

