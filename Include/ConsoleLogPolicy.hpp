#pragma once

#include <iostream>
#include "ILoggerPolicy.hpp"

class ConsoleLogPolicy : public ILoggerPolicy
{
protected:
	template <class ... T> friend class Logger;

	void applyPolicy(std::string& buffer) override
	{
		std::cout << buffer << std::endl;;
	}
};
