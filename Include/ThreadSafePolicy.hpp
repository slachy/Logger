#pragma once

#include <iostream>
#include <mutex>
#include "ILoggerPolicy.hpp"

class ThreadSafePolicy : public ILoggerPolicy
{
private:
    static std::mutex mutex;

public:
	~ThreadSafePolicy()
	{
		mutex.unlock();
	}
protected:
	template <class ... T> friend class Logger;

	void applyPolicy(std::string&) override
	{
        mutex.lock();
	}
};

std::mutex ThreadSafePolicy::mutex;
