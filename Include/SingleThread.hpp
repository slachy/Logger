#pragma once

class SingleThread
{
protected:
	~SingleThread() {}

public:
	void lock() {}
	void unlock() {}
};
