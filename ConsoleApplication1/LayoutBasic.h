//#pragma once
#include <thread>
#include <ctime>
#include <time.h>
#include <sstream>
#include <iomanip>
#include "LayoutBase.h"

namespace jLogger
{
	class LayoutBasic : public LayoutBase
	{
	public:
		virtual ~LayoutBasic() override
		{};

		static std::string timeConvert(const jTime& n_time)
		{
			struct tm buf;
			auto cTime = std::chrono::system_clock::to_time_t(n_time);
			localtime_s(&buf, &cTime);
			std::stringstream ss;
			ss << std::put_time(&buf, "%Y-%m-%d %H:%M:%S.");

			auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(n_time);
			auto fraction = n_time - seconds;
			auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
			
			ss << std::setw(3) << std::setfill('0') << milliseconds.count();
			
			return ss.str();
		}

		// Inherited via LayoutBase
		virtual std::string format(const jLogger::LogEvent &n_logEvent) override
		{
			std::string result;
			
			auto this_thread_id = std::hash<std::thread::id>() (n_logEvent.getThreadId());
			result.append( timeConvert(n_logEvent.getTime()) );
			result.append(" ");
			result.append( logLevelToString( n_logEvent.getEvenetLevel() ) );
			result.append(" ");
			result.append(std::to_string(this_thread_id));
			result.append(" ");
			
			if(!n_logEvent.getFunctionName().empty())
			{
				result.append(n_logEvent.getFunctionName());
				result.append(" ");
			}
			
			if (!n_logEvent.getFileName().empty())
			{
				result.append(n_logEvent.getFileName());
				result.append(" ");
			}

			if (!n_logEvent.getLineNumber() == 0)
			{
				result.append(std::to_string(n_logEvent.getLineNumber()));
				result.append(" ");
			}

			result.append(n_logEvent.getMsg());
			return result;
		}
	};
}