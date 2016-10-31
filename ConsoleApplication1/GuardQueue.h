#pragma once
#include <queue>
#include <mutex>

namespace jLogger
{
	template <typename T>
	class GuardQueue
	{
		std::queue<T> m_queue;
		mutable std::mutex m_mutex;
		std::condition_variable m_dataConditional;

		GuardQueue(const GuardQueue&) = delete;
		GuardQueue& operator=(const GuardQueue&) = delete;

	public:
		GuardQueue() {}

		void push(T n_item)
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			m_queue.push(n_item);
			m_dataConditional.notify_one();
		}

		T pop()
		{
			std::unique_lock<std::mutex> lock(m_mutex);
			while(m_queue.empty())
			{
				m_dataConditional.wait(lock);
			}
			T result = m_queue.front();
			m_queue.pop();
			return result;
		}

		bool empty() const
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			return m_queue.empty();
		}

		std::size_t size() const
		{
			std::lock_guard<std::mutex> lock(m_mutex);
			return m_queue.size();
		}

	};
}