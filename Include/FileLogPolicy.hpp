#pragma once

#include <iostream>
#include <fstream>

class FileLogPolicy
{
public:
	FileLogPolicy() {}
	FileLogPolicy(const FileLogPolicy& copy) = delete;
	FileLogPolicy(FileLogPolicy&& other) : fileStream(std::move(other.fileStream)) {}
	~FileLogPolicy()
	{
		close();
	}
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

	void applyPolicy(std::string& buffer)
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
