//#pragma once
#include <string>

namespace jLogger
{
	enum class LogLevel : uint32_t {
		TRACE_ = 0,
		DEBUG_ = 1,
		WARNING_ = 2,
		ERROR_ = 3,
		FATAL_ = 4
	} ;

	std::string logLevelToString(const LogLevel n_logLevel);
}
