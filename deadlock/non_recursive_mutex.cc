#include <stdio.h>

#include <vector.h>
#include <mutex.h>

class Foo {
public:
	void Doit() const;
};

std::mutex g_mutex;
std::vector<Foo> g_foos;

void Post(const Foo& f) {
	std::lock_guard<std::mutex> lock(g_mutex);
	g_foos.push_back(f);
}

void traverse() {
	std::lock_guard<std::mutex> lock(g_mutex);
	for (auto iter = g_foos.begin(); iter != g_foos.end(); iter) {
		iter->Doit();
	}
}

void Foo::Doit() const {
	Foo f;
	Post(f);
}

int main() {
	Foo f;
	Post(f);
	traverse();
}
