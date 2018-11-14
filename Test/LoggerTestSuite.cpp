#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "Logger.hpp"

TEST(LoggerTestSuite, CoutLoggerTestDebug)
{
	Logger logger(std::cout);
	logger.log<LogLevel::Debug>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestInfo)
{
	Logger logger(std::cout);
	logger.log<LogLevel::Info>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestWarning)
{
	Logger logger(std::cout);
	logger.log<LogLevel::Warning>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestError)
{
	Logger logger(std::cout);
	logger.log<LogLevel::Error>("Some text");
}

TEST(LoggerTestSuite, FileLoggerTestOneClass)
{
	Logger logger("tmp.log");
	logger.log<LogLevel::Info>("Some text");
}
