#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "Logger.hpp"

TEST(LoggerTestSuite, CoutLoggerTest)
{
	Logger logger(std::cout);
	ASSERT_TRUE(logger.log("Some text"));
}

TEST(LoggerTestSuite, FileLoggerTestOneClass)
{
	Logger logger("tmp.log");
	ASSERT_TRUE(logger.log("Some text"));
}
