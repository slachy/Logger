#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "LogLevel.hpp"

namespace Color
{
    static const std::string RED = "\033[0;31m";
    static const std::string BLUE = "\033[0;34m";
}

class LogLevelColorPolicy
{
public:
	template <LogLevel Level>
    void setColor(std::string color)
	{
		logLevelsWithColors.emplace_back(logLevelToStr<Level>(), color);
	}

	void applyPolicy(std::string& buffer)
	{
		std::string noColor("\033[0m");

		for (auto elem : logLevelsWithColors)
		{
            const std::string toReplace = elem.first;
			const std::string color = elem.second;
		    const size_t pos = buffer.find(toReplace);
			if (pos != std::string::npos)
			{
		        buffer.replace(pos, toReplace.length(), color + toReplace + noColor);
			}
		}
	}
private:
	std::vector<std::pair<std::string, std::string>> logLevelsWithColors;

};

