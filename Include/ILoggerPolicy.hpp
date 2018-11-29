#pragma once


class ILoggerPolicy
{
protected:
	template <class ... T> friend class Logger;

	virtual void applyPolicy(std::string&) = 0;
};
