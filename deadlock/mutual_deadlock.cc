#include <unistd.h> // sleep

#include <set>
#include <mutex> // mutex lock_guard
#include <thread>

class Request;

class Inventory {
public:
	void Add(Request* req) {
		std::lock_guard<std::mutex> lock(mutex_);
		requests_.insert(req);
	}

	void Remove(Request* req) {
		std::lock_guard<std::mutex> lock(mutex_);
		requests_.erase(req);
	}
	
	void PrintAll() const;

private:
	mutable std::mutex mutex_;
	std::set<Request*> requests_;
};

Inventory g_inventory;

class Request {
public:
	void Process() {
		std::lock_guard<std::mutex> lock(mutex_);
		g_inventory.Add(this);
	}

	void Print() {
		std::lock_guard<std::mutex> lock(mutex_);
		printf("print");
	}

	~Request() {
		std::lock_guard<std::mutex> lock(mutex_);
		sleep(1);
		g_inventory.Remove(this);
	}

private:
	mutable std::mutex mutex_;
};

void Inventory::PrintAll() const {
	std::lock_guard<std::mutex> lock(mutex_);
	sleep(1);
	for (auto iter = requests_.begin(); iter != requests_.end(); iter++) {
		(*iter)->Print();
	}
	printf("Inventory::PrintAll() unlocked\n");
}


void ThreadFunc() {
	Request* req = new Request;
	req->Process();
	delete req;
}

int main() {
	std::thread thr(ThreadFunc);
	usleep(500 * 1000);
	g_inventory.PrintAll();
	thr.join();
}
