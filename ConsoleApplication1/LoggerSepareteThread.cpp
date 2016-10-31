#include "LoggerSepareteThread.h"


jLogger::LoggerSepareteThread::LoggerSepareteThread(std::ostream& n_stream,
	std::unique_ptr<LayoutBase> n_layout,
	const LogLevel n_logLevel)
	: LoggerStream(n_stream,
		std::move(n_layout),
		n_logLevel),
	m_workerGo(true),
	m_worker([this] { worker(); })
{
}


jLogger::LoggerSepareteThread::~LoggerSepareteThread()
{
	m_workerGo = false;
	LogEvent lastEvent("last");
	lastEvent.m_isLastEvent = true;
	m_queue.push(lastEvent);
	m_worker.join();
	m_stream.flush();
}

void jLogger::LoggerSepareteThread::worker()
{
	while(m_workerGo || !m_queue.empty())
	{
		LogEvent event = m_queue.pop();
		if (event.m_isLastEvent)
			break;
		m_stream << m_layout->format(event) << std::endl;
	}
}

void jLogger::LoggerSepareteThread::traceProt(std::string n_msg)
{
	m_queue.push( (LogEvent(n_msg, LogLevel::TRACE_)) );
}

void jLogger::LoggerSepareteThread::traceProt(std::string n_msg, const std::string & n_func, const std::string & n_fileName, const int n_lineNum, const std::thread::id & n_threadId)
{
	m_queue.push((LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::TRACE_)));
	
}

void jLogger::LoggerSepareteThread::debugProt(std::string n_msg)
{
	m_queue.push((LogEvent(n_msg, LogLevel::DEBUG_)));
}

void jLogger::LoggerSepareteThread::debugProt(std::string n_msg, const std::string & n_func, const std::string & n_fileName, const int n_lineNum, const std::thread::id & n_threadId)
{
	m_queue.push((LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::DEBUG_)));
}

void jLogger::LoggerSepareteThread::warningProt(std::string n_msg)
{
	m_queue.push((LogEvent(n_msg, LogLevel::WARNING_)));
}

void jLogger::LoggerSepareteThread::warningProt(std::string n_msg, const std::string & n_func, const std::string & n_fileName, const int n_lineNum, const std::thread::id & n_threadId)
{
	m_queue.push((LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::WARNING_)));
}

void jLogger::LoggerSepareteThread::errorProt(std::string n_msg)
{
	m_queue.push((LogEvent(n_msg, LogLevel::ERROR_)));
}

void jLogger::LoggerSepareteThread::errorProt(std::string n_msg, const std::string & n_func, const std::string & n_fileName, const int n_lineNum, const std::thread::id & n_threadId)
{
	m_queue.push((LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::ERROR_)));
}

void jLogger::LoggerSepareteThread::fatalProt(std::string n_msg)
{
	m_queue.push((LogEvent(n_msg, LogLevel::FATAL_)));
}

void jLogger::LoggerSepareteThread::fatalProt(std::string n_msg, const std::string & n_func, const std::string & n_fileName, const int n_lineNum, const std::thread::id & n_threadId)
{
	m_queue.push((LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::FATAL_)));
}
