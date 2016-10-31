//#pragma once
#include <chrono>
#include "Types.h"

namespace jLogger
{
	typedef std::chrono::system_clock::time_point jTime;

	class LoggerSepareteThread;
	class LogEvent
	{
	public:

		LogEvent(const std::string& n_msg,
			const LogLevel n_eventLevel = LogLevel::TRACE_)
			: m_msg(n_msg),
			m_eventLevel(n_eventLevel),
			m_rowTime(std::chrono::system_clock::now()),
			m_isLastEvent(false),
			m_lineNum(0)
		{

		}

		LogEvent(const std::string& n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId,
			const LogLevel n_eventLevel = LogLevel::TRACE_)
			: m_msg(n_msg),
			m_eventLevel(n_eventLevel),
			m_rowTime(std::chrono::system_clock::now()),
			m_func(n_func),
			m_fileName(n_fileName),
			m_lineNum(n_lineNum),
			m_threadId(n_threadId),
			m_isLastEvent(false)
		{

		}

		std::string getMsg() const
		{
			return m_msg;
		}

		LogLevel getEvenetLevel() const
		{
			return m_eventLevel;
		}

		jTime getTime() const
		{
			return m_rowTime;
		}

		std::string getFunctionName() const
		{
			return m_func;
		}

		std::string getFileName() const
		{
			return m_fileName;
		}

		int getLineNumber() const
		{
			return m_lineNum;
		}

		std::thread::id getThreadId() const
		{
			return m_threadId;
		}
	private:
		friend LoggerSepareteThread;
		const std::string m_msg;
		const LogLevel m_eventLevel;
		const jTime m_rowTime;
		const std::string m_func;
		const std::string m_fileName;
		const int m_lineNum;
		const std::thread::id m_threadId;
		bool m_isLastEvent;
	};
}
