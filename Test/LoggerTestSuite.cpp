#include <gtest/gtest.h>
#include <iostream>
#include "Logger.hpp"

TEST(LoggerTestSuite, SimpleLoggerTest)
{
	Logger logger(std::cout);
	logger.log("Some text");

}
