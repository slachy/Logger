#pragma once

#include <iostream>

struct ConsoleWriter
{

    template <class T>
	void write(T& buffer)
	{
		std::cout << buffer << std::endl;;
	}
protected:
	~ConsoleWriter() {}
};
