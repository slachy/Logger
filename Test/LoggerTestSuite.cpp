#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "Logger.hpp"
#include "ConsoleLogPolicy.hpp"
#include "FileLogPolicy.hpp"

TEST(LoggerTestSuite, CoutLoggerTestDebug)
{
	Logger<ConsoleLogPolicy> logger;
	logger.log<LogLevel::Debug>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestInfo)
{
	Logger<ConsoleLogPolicy> logger;
	logger.log<LogLevel::Info>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestWarning)
{
	Logger<ConsoleLogPolicy> logger;
	logger.log<LogLevel::Warning>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestError)
{
	Logger<ConsoleLogPolicy> logger;
	logger.log<LogLevel::Error>("Some text");
}

TEST(LoggerTestSuite, FileLoggerTestOneClass)
{
	Logger<FileLogPolicy> logger;
	logger.getPolicy()->open("tmp.log");
	logger.log<LogLevel::Info>("Some text");
}
