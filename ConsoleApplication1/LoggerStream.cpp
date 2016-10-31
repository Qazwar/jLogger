#include "LoggerStream.h"

jLogger::LoggerStream::LoggerStream(std::ostream & n_stream,
	std::unique_ptr<LayoutBase> n_layout,
	const LogLevel n_logLevel)
	: LoggerBase(std::move(n_layout), n_logLevel),
	m_stream(n_stream)
{

}

jLogger::LoggerStream::~LoggerStream()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream.flush();
}

void jLogger::LoggerStream::traceProt(std::string n_msg)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, LogLevel::TRACE_)) << "\n";
}

void jLogger::LoggerStream::traceProt(std::string n_msg,
	const std::string & n_func,
	const std::string & n_fileName,
	const int n_lineNum,
	const std::thread::id & n_threadId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::TRACE_)) << "\n";
}

void jLogger::LoggerStream::debugProt(std::string n_msg)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, LogLevel::DEBUG_)) << "\n";
}

void jLogger::LoggerStream::debugProt(std::string n_msg,
	const std::string & n_func,
	const std::string & n_fileName,
	const int n_lineNum,
	const std::thread::id & n_threadId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::DEBUG_)) << "\n";
}

void jLogger::LoggerStream::warningProt(std::string n_msg)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, LogLevel::WARNING_)) << "\n";
}

void jLogger::LoggerStream::warningProt(std::string n_msg,
	const std::string & n_func,
	const std::string & n_fileName,
	const int n_lineNum,
	const std::thread::id & n_threadId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::WARNING_)) << "\n";
}

void jLogger::LoggerStream::errorProt(std::string n_msg)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, LogLevel::ERROR_)) << "\n";
}

void jLogger::LoggerStream::errorProt(std::string n_msg,
	const std::string & n_func,
	const std::string & n_fileName,
	const int n_lineNum,
	const std::thread::id & n_threadId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::ERROR_)) << "\n";
}

void jLogger::LoggerStream::fatalProt(std::string n_msg)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, LogLevel::FATAL_)) << "\n";
}

void jLogger::LoggerStream::fatalProt(std::string n_msg,
	const std::string & n_func,
	const std::string & n_fileName,
	const int n_lineNum,
	const std::thread::id & n_threadId)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	m_stream << m_layout->format(LogEvent(n_msg, n_func, n_fileName, n_lineNum, n_threadId, LogLevel::FATAL_)) << "\n";
}