#pragma once

#include <iostream>
#include <mutex>

class ThreadSafePolicy
{
private:
    static std::mutex mutex;

public:
	~ThreadSafePolicy()
	{
		mutex.unlock();
	}

	void applyPolicy(std::string&)
	{
        mutex.lock();
	}
};

std::mutex ThreadSafePolicy::mutex;
