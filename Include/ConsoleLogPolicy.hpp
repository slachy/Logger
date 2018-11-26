#pragma once

#include <iostream>

class ConsoleLogPolicy
{
protected:
	template <class T> friend class Logger;

	void write(const std::string& buffer)
	{
		std::cout << buffer;
	}
};


