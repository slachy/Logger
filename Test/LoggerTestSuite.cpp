#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <thread>

#include "Logger.hpp"
#include "ConsoleLogPolicy.hpp"
#include "FileLogPolicy.hpp"
#include "ThreadSafePolicy.hpp"
#include "LogLevelColorPolicy.hpp"

TEST(LoggerTestSuite, CoutLoggerTest)
{
	Logger<ConsoleWriter> logger;
	logger.log<LogLevel::Debug>("Some text");
}

TEST(LoggerTestSuite, FileLoggerTest)
{
	Logger<FileWriter> logger;
	logger.open("FileLoggerTest.log");
	logger.log<LogLevel::Info>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestInfo)
{
	Logger<ConsoleWriter> logger;
	logger.log<LogLevel::Info>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestWarning)
{
	Logger<ConsoleWriter> logger;
	logger.log<LogLevel::Warning>("Some text");
}

TEST(LoggerTestSuite, CoutLoggerTestError)
{
	Logger<ConsoleWriter> logger;
	logger.log<LogLevel::Error>("Some text");
}
/*
TEST(LoggerTestSuite, FileLoggerTest)
{
	Logger<FileLogPolicy> logger;
	logger.getPolicy<FileLogPolicy>()->open("FileLoggerTest.log");
	logger.log<LogLevel::Info>("Some text");
}

/*TEST(LoggerTestSuite, FileAndConsoleLoggerTest)
{
	Logger<ConsoleLogPolicy, FileLogPolicy> logger;
	logger.getPolicy<FileLogPolicy>()->open("FileAndConsoleLoggerTest.log");
	logger.log<LogLevel::Error>("Some text");
}

void firstThread()
{
    Logger<ThreadSafePolicy, ConsoleLogPolicy> logger;
    logger.log<LogLevel::Debug>("Text logged from first thread");
}

void secondThread()
{
    Logger<ThreadSafePolicy, ConsoleLogPolicy> logger;
    logger.log<LogLevel::Info>("Text logged from second thread");
}

TEST(LoggerTestSuite, ThreadSafeCoutLoggerTest)
{
	std::thread threadOne(firstThread);
	std::thread threadTwo(secondThread);

	threadTwo.join();
	threadOne.join();
}

TEST(LoggerTestSuite, ColorPolicyCoutTest)
{
	Logger<LogLevelColorPolicy, ConsoleLogPolicy> logger;
	logger.getPolicy<LogLevelColorPolicy>()->setColor<LogLevel::Error>(Color::RED);
	logger.getPolicy<LogLevelColorPolicy>()->setColor<LogLevel::Info>(Color::BLUE);
	logger.log<LogLevel::Error>("Some text");
	logger.log<LogLevel::Info>("Some other text");
}*/
