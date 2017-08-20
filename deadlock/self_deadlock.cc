#include <stdio.h>

#include <mutex>

class Request {
public:
	void process() __attribute__((noinline)) {
		std::lock_guard<std::mutex> lock(mutex_);
		print();
	}

	void print() const __attribute__((noinline)) {
		std::lock_guard<std::mutex> lock(mutex_);
		printf("print");
	}

private:
	mutable std::mutex mutex_;
};

int main() {
	Request req;
	req.process();
}
