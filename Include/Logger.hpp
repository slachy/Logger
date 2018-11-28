#pragma once

#include <string>
#include <fstream>
#include <type_traits>
#include <tuple>
#include <ctime>
#include <iomanip>
#include <sstream>

enum class LogLevel { Debug, Info, Warning, Error };

template <LogLevel Level>
std::string logLevelToStr()
{
    return std::string("Default log level implementation");
}
template <>
std::string logLevelToStr<LogLevel::Info>()
{
    return std::string("[INFO] ");
}

template <>
std::string logLevelToStr<LogLevel::Debug>()
{
    return std::string("[DEBUG] ");
}

template <>
std::string logLevelToStr<LogLevel::Warning>()
{
    return std::string("[WARNING] ");
}

template <>
std::string logLevelToStr<LogLevel::Error>()
{
    return std::string("[ERROR] ");
}

template <class ... Policies>
class Logger
{
private:
	std::tuple<Policies...> policies;
	static const size_t numOfPolicies = sizeof...(Policies);

public:
	Logger() : policies { std::forward<Policies>(Policies{})... } {}

	template <LogLevel Level>
	void log(std::string str)
	{
	    auto t = std::time(nullptr);
	    auto timestamp = *std::localtime(&t);
		std::ostringstream oss;
		oss << std::put_time(&timestamp, "%d-%m-%Y:%H-%M-%S");
		std::string logLevelStr;
		logLevelStr = logLevelToStr<Level>();

		doPolicy<0>(policies, oss.str() + " " + logLevelStr + str);
	}

	template <typename T>
	T* getPolicy()
	{
		static const auto index = findTypeIndex<T, Policies...>::value;
	    return getPolicy<index>();
	}

	template <size_t Index>
    auto getPolicy() -> decltype(&std::get<Index>(policies))
	{
		static_assert(Index < numOfPolicies, "Policy index out of range");
		return &std::get<Index>(policies);
	}

private:
    template <size_t I>
	typename std::enable_if<I != numOfPolicies>::type doPolicy(std::tuple<Policies...>& p, const std::string& str)
	{
		std::get<I>(p).applyPolicy(str);
		doPolicy<I+1>(p, str);
	}

	template <size_t I>
    typename std::enable_if<I == numOfPolicies>::type doPolicy(std::tuple<Policies...>& p, const std::string& str)
	{
	}

	template <typename... >
	struct findTypeIndex;

	template <typename T, typename... R>
	struct findTypeIndex<T, T, R...> : std::integral_constant<size_t, 0>  {};

	template <typename T, typename F, typename... R>
    struct findTypeIndex<T, F, R...> : std::integral_constant<size_t, 1 + findTypeIndex<T, R...>::value> {};
};


