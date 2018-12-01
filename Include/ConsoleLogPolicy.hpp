#pragma once

#include <iostream>

class ConsoleLogPolicy
{
public:

	void applyPolicy(std::string& buffer)
	{
		std::cout << buffer << std::endl;;
	}
};
