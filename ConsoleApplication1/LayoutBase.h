#pragma once
#include "LogEvenet.h"

namespace jLogger
{
	class LayoutBase
	{

	public:

		inline virtual ~LayoutBase() = 0
		{};

		virtual std::string format(const LogEvent& n_logEvent) = 0;
		
	};
}