#pragma once


class ILoggerPolicy
{
protected:
	template <class ... T> friend class Logger;

	virtual void applyPolicy(const std::string&) = 0;
};
