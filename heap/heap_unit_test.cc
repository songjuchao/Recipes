#include <iostream>

#include "heap.h"

void unitTest() {
	// Heap<int> heap({1, 2, 3, 4, 5});
	Heap<int> heap({5, 4, 3, 2, 1});
	auto heapVec = heap.getHeap();
	for (auto iter = heapVec.begin(); iter != heapVec.end(); iter++) {
		std::cout << *iter << std::endl;
	}
}

int main() {
	unitTest();
}
