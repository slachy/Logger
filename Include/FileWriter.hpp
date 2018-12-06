#pragma once

#include <iostream>
#include <fstream>

class FileWriter 
{
protected:
	~FileWriter()
	{
		close();
	}
public:
	bool open(const std::string& filename)
	{
		fileStream.open(filename);

		if (not fileStream.is_open())
		{
			std::cerr << "FileLogPolicy Error: Faild to open file '" << filename << std::endl;
			return false;
		}

		fileStream << "-- File Log Started -- " << std::endl;
		return true;
	}

	void close()
	{
		if (fileStream.is_open())
		{
			fileStream << "-- File Log Ended -- " << std::endl;
			fileStream.close();
		}
	}

    template <class T>
	void write(T& buffer)
	{
		if (fileStream)
		{
			fileStream << buffer << std::endl;
		}
		else
		{
			std::cerr << "FileLogPolicy Error: File stream is not open for writing." << std::endl;
		}
	}

private:
	std::ofstream fileStream;
};
