#pragma once

#include <iostream>
#include <mutex>

class ThreadSafe
{
private:
    static std::mutex mutex;

protected:
	~ThreadSafe()
	{
		unlock();
	}

public:
	void lock()
	{
        mutex.lock();
	}
    void unlock()
	{
        mutex.unlock();
	}
};

std::mutex ThreadSafe::mutex;
