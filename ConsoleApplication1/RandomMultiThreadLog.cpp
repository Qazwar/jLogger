
#include "LoggerSepareteThread.h"
#include <fstream>
#include <random>

void randomLog(jLogger::LoggerBase * n_logger,
	const std::string& n_msg)
{
	switch (static_cast<jLogger::LogLevel>(rand() % 5))
	{
	case jLogger::LogLevel::TRACE_:
		n_logger->traceExt(n_msg);
		break;
	case jLogger::LogLevel::DEBUG_:
		n_logger->debugExt(n_msg);
		break;
	case jLogger::LogLevel::WARNING_:
		n_logger->warningExt(n_msg);
		break;
	case jLogger::LogLevel::ERROR_:
		n_logger->errorExt(n_msg);
		break;
	case jLogger::LogLevel::FATAL_:
		n_logger->fatalExt(n_msg);
		break;
	}
}

void multiThreadLogging(jLogger::LoggerBase * n_logger,
	const std::string& n_msg)
{
	for (int i = 0; i < 1000; ++i)
	{
		randomLog(n_logger, n_msg);
		std::chrono::milliseconds duration(20);
		std::this_thread::sleep_for(duration);
	}
}

static const size_t threadsCount = 8;

int main()
{
	try
	{
		std::srand((unsigned int) time(0));
		std::thread t[threadsCount];
		std::ofstream file("file.txt");
		
		//jLogger::LoggerStream logger(file, std::make_unique<jLogger::LayoutBasic>());
		jLogger::LoggerSepareteThread logger(file, std::make_unique<jLogger::LayoutBasic>());
		
		for (size_t i = 0; i < threadsCount; ++i)
		{
			const std::string msg("msg");
			t[i] = std::thread(multiThreadLogging, &logger, msg);
		}

		for (size_t i = 0; i < threadsCount; ++i)
		{
			t[i].join();
		}
		
	}
	catch (...)
	{
		std::cout << "Unknown exception";
	}
	return 0;
}

