//#include "stdafx.h"
#include "Types.h"

std::string jLogger::logLevelToString(const LogLevel n_logLevel)
{
	switch (n_logLevel)
	{
	case LogLevel::TRACE_:
		return "TRACE";
	case LogLevel::DEBUG_:
		return "DEBUG";
	case LogLevel::WARNING_:
		return "WARNING";
	case LogLevel::ERROR_:
		return "ERROR";
	case LogLevel::FATAL_:
		return "FATAL";
	default:
		return "";
	}
}
