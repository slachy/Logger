#pragma once

#include <iostream>
#include <mutex>
#include "ILoggerPolicy.hpp"

class ThreadSafePolicy : public ILoggerPolicy
{
protected:
	template <class ... T> friend class Logger;

	void applyPolicy(const std::string&) override
	{
		// TODO make it locked for real
		std::cout << "<LOCK> ";
	    std::mutex mutex;
		std::lock_guard<std::mutex> lock(mutex);
	}

private:
};
