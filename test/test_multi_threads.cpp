#include <gtest/gtest.h>
#include <thread>
#include <mutex>
int kMultiCount = 0;
std::mutex mt;

void func(const int id, const int k) {
	int s = 0;
	mt.lock();
	for(int i = 1; i <= k; ++i) s += i;
	mt.unlock();
	std::cout << "total(" << id <<")=" << s << std::endl;
	std::cout<< "thread " << ++kMultiCount << " finished\n";
}

TEST(MultiThreads, common)
{
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++) threads.emplace_back(func, i, 2);
	for(int i = 0; i < 10; i++)
		threads[i].join();
}