//#pragma once
#include "LoggerStream.h"
#include "GuardQueue.h"

namespace jLogger
{
	class LoggerSepareteThread :
		public LoggerStream
	{
	public:
		explicit LoggerSepareteThread(std::ostream& n_stream = std::cout,
			std::unique_ptr<LayoutBase> n_layout = std::unique_ptr<LayoutBase>(new LayoutBasic()),
			const LogLevel n_logLevel = LogLevel::TRACE_);
		~LoggerSepareteThread();

		LoggerSepareteThread(const LoggerSepareteThread&) = delete;
		LoggerSepareteThread& operator=(const LoggerSepareteThread&) = delete;

		void worker();
	protected:
		// Inherited via LoggerStream
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


	private:
		GuardQueue<LogEvent> m_queue;
		volatile bool m_workerGo;
		std::thread m_worker;
	};
}