#pragma once

#include <iostream>

template <class T>
struct ConsoleWriter
{
	void write(T& buffer)
	{
		std::cout << buffer << std::endl;;
	}
};
