#include "mthread_queue/bufferqueue.hpp"
#include <iostream>
#include <thread>
#include <cstring>

bool packet_scale_flag = true;
 
void get_packet(WorkersQueue& packet_scale) {
	int i = 0;
	while(packet_scale_flag) {

		DataBuffer buffer;
		packet_scale.popProducer(buffer);
		fprintf(stderr, "%s", buffer.data);
		char b[100];
		snprintf(b, 100, "get_packet %d\n", i++);
		memcpy(buffer.data, b, sizeof(b));
		packet_scale.pushConsumer(buffer);
		if(i > 1000) break;
	}
}
 
void get_scale(WorkersQueue& packet_scale) {
	int i = 0;
	while (packet_scale_flag) {
		DataBuffer buffer;
		packet_scale.popConsumer(buffer);
		fprintf(stderr, "%s", buffer.data);
		char b[100];
		snprintf(b, 100, "scale %d\n", i++);
		memcpy(buffer.data, b, sizeof(b));
		packet_scale.pushProducer(buffer);
		// char c;
		// c = getchar();
		// if(c == 'Q') {
		// 	packet_scale_flag = false;
		// }
		if(i > 1000) break;
	}
}

int main(int argc, char const *argv[]) {
	std::cout << Timer::getCurrentTime() << std::endl;
	WorkersQueue works;
	works.Init(4, 1024);
 
	std::thread thread_packet(get_packet, std::ref(works));
	std::thread thread_scale(get_scale, std::ref(works));
 
	thread_packet.join();
	thread_scale.join();
	return 0;
}