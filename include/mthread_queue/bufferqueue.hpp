#ifndef CF_INCLUDE_BUFFER_QUEUE_HPP_
#define CF_INCLUDE_BUFFER_QUEUE_HPP_
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>
class Timer {
public:
	static long long getCurrentTime() {
		auto now = std::chrono::system_clock::now();
		return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	}
};

typedef struct DataBuffer {
	unsigned char* data;
	unsigned int length;
} DataBuffer;

class BufferQueue {
public:
	BufferQueue() = default;
	void push(DataBuffer& _buffer){
		std::unique_lock<std::mutex> lck(mtx);
		queue.push(_buffer);
		cv.notify_all();
	}
	void pop(DataBuffer& _buffer) {
		std::unique_lock<std::mutex> lck(mtx);
		while(queue.empty()) {
			cv.wait(lck);
		}
		_buffer = queue.front();
		queue.pop();
	}
	unsigned int size() {
		return queue.size();
	}
private:
	std::mutex mtx;
	std::condition_variable cv;
	std::queue<DataBuffer> queue;
};

class WorkersQueue {
public:
	WorkersQueue() = default;
	void Init(size_t buffer_num = 16, unsigned int buffer_size=1024*1024*4) {
		for(size_t i = 0; i < buffer_num; i++) {
			DataBuffer buffer = {new unsigned char[buffer_size], buffer_size};
			pushProducer(buffer);
		}
	}
	~WorkersQueue() {
		DataBuffer buffer;
 
		while (getProducerSize() > 0) {
			popProducer(buffer);
			delete[] buffer.data;
		}
 
		while (getConsumerSize() > 0) {
			popConsumer(buffer);
			delete[] buffer.data;
		}
	}
	void pushProducer(DataBuffer& buffer) {
		producers.push(buffer);
	}
	void popProducer(DataBuffer& buffer) {
		producers.pop(buffer);
	}
	size_t getProducerSize() {
		return producers.size();
	}
	void pushConsumer(DataBuffer& buffer) {
		consumers.push(buffer);
	}
	void popConsumer(DataBuffer& buffer) {
		consumers.pop(buffer);
	}
	size_t getConsumerSize() {
		return consumers.size();
	}
private:
	BufferQueue producers;
	BufferQueue consumers;
};
#endif