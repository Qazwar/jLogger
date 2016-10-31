//#pragma once
#include <iostream>
#include <mutex>
#include "LoggerBase.h"

namespace jLogger
{

	class LoggerStream : public LoggerBase
	{
	public:
		explicit LoggerStream(std::ostream& n_stream = std::cout,
			std::unique_ptr<LayoutBase> n_layout = std::unique_ptr<LayoutBase>(new LayoutBasic()),
			const LogLevel n_logLevel = LogLevel::TRACE_);

		virtual ~LoggerStream();

		LoggerStream(const LoggerStream&) = delete;
		LoggerStream& operator=(const LoggerStream&) = delete;
	protected:
		// Inherited via LoggerBase
		virtual void traceProt(std::string n_msg) override;
		virtual void traceProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) override;
		virtual void debugProt(std::string n_msg) override;
		virtual void debugProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) override;
		virtual void warningProt(std::string n_msg) override;
		virtual void warningProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) override;
		virtual void errorProt(std::string n_msg) override;
		virtual void errorProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) override;
		virtual void fatalProt(std::string n_msg) override;
		virtual void fatalProt(std::string n_msg,
			const std::string& n_func,
			const std::string& n_fileName,
			const int n_lineNum,
			const std::thread::id& n_threadId) override;

	protected:
		mutable std::mutex m_mutex;
		std::ostream & m_stream;		
	};
}