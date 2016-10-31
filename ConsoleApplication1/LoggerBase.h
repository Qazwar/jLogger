//#pragma once
#include <memory>
#include "LayoutBasic.h"



namespace jLogger
{
	class LoggerBase
	{
	public:
		explicit LoggerBase(std::unique_ptr<LayoutBase> n_layout = std::unique_ptr<LayoutBase>(new LayoutBasic()),
			const LogLevel n_logLevel = LogLevel::TRACE_)
			: m_logLevel(n_logLevel),
			m_layout(std::move(n_layout))
		{

		}

		virtual ~LoggerBase() = 0 {};

		LoggerBase(const LoggerBase&) = delete;
		LoggerBase& operator=(const LoggerBase&) = delete;

		void trace(std::string n_msg)
		{
			if (m_logLevel <= LogLevel::TRACE_)
			{
				traceProt(n_msg);
			}
		}

		void traceExt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId)
		{
			if (m_logLevel <= LogLevel::TRACE_)
			{
				traceProt(n_msg,
					n_func,
					n_fileName,
					n_lineNum,
					n_threadId);
			}
		}

		void debug(std::string n_msg)
		{
			if (m_logLevel <= LogLevel::DEBUG_)
			{
				debugProt(n_msg);
			}
		}
		void debugExt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId)
		{
			if (m_logLevel <= LogLevel::DEBUG_)
			{
				debugProt(n_msg,
					n_func,
					n_fileName,
					n_lineNum,
					n_threadId);
			}
		}

		void warning(std::string n_msg)
		{
			if (m_logLevel <= LogLevel::WARNING_)
			{
				warningProt(n_msg);
			}
		}
		void warningExt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId)
		{
			if (m_logLevel <= LogLevel::WARNING_)
			{
				warningProt(n_msg,
					n_func,
					n_fileName,
					n_lineNum,
					n_threadId);
			}
		}

		void error(std::string n_msg)
		{
			if (m_logLevel <= LogLevel::ERROR_)
			{
				errorProt(n_msg);
			}
		}
		void errorExt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId)
		{
			if (m_logLevel <= LogLevel::ERROR_)
			{
				errorProt(n_msg,
					n_func,
					n_fileName,
					n_lineNum,
					n_threadId);
			}
		}

		void fatal(std::string n_msg)
		{
			if (m_logLevel <= LogLevel::FATAL_)
			{
				fatalProt(n_msg);
			}
		}
		void fatalExt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId)
		{
			if (m_logLevel <= LogLevel::FATAL_)
			{
				fatalProt(n_msg,
					n_func,
					n_fileName,
					n_lineNum,
					n_threadId);
			}
		}

	protected:
		virtual void traceProt(std::string n_msg) = 0;
		virtual void traceProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) = 0;
		virtual void debugProt(std::string n_msg) = 0;
		virtual void debugProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) = 0;
		virtual void warningProt(std::string n_msg) = 0;
		virtual void warningProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) = 0;
		virtual void errorProt(std::string n_msg) = 0;
		virtual void errorProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) = 0;
		virtual void fatalProt(std::string n_msg) = 0;
		virtual void fatalProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) = 0;

		std::unique_ptr<LayoutBase> m_layout;
	private:
		 LogLevel m_logLevel;
		 
	};

}

#define traceExt(x) traceExt(x, __FUNCTION__, __FILE__, __LINE__, std::this_thread::get_id())
#define debugExt(x) debugExt(x, __FUNCTION__, __FILE__, __LINE__, std::this_thread::get_id())
#define warningExt(x) warningExt(x, __FUNCTION__, __FILE__, __LINE__, std::this_thread::get_id())
#define errorExt(x) errorExt(x, __FUNCTION__, __FILE__, __LINE__, std::this_thread::get_id())
#define fatalExt(x) fatalExt(x, __FUNCTION__, __FILE__, __LINE__, std::this_thread::get_id())