#pragma once

#include <string>

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
