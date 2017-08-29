#ifndef _HEAP_H_
#define _HEAP_H_

#include <vector>
#include <initializer_list>
#include <algorithm>

// Bigger root heap
template<typename T>
class Heap {
public:
	Heap() = default;
	Heap(std::initializer_list<T> l) {
		heap_.insert(heap_.begin(), l.begin(), l.end());
		buildHeap(heap_.size());
		heapSort();
	}

	std::vector<T> getHeap() { return heap_; }

private:
	int leftChild(int i) { return 2 * i + 1; }
	int rightChild(int i) { return 2 * i + 2; }

	// adjust root to keep heap's property
	void heapify(int root, int size) {
		if (root >= size) {
			return;
		}

		int child;
		int rootVal;

		for (rootVal = heap_[root]; leftChild(root) < size; root = child) {
			child = leftChild(root);
			if (rightChild(root) < size && heap_[child] < heap_[rightChild(root)]) {
				child = rightChild(root);
			}

			if (rootVal < heap_[child]) {
				heap_[root] = heap_[child];
			} else {
				break;
			}
		}
		heap_[root] = rootVal;
	}

	void buildHeap(int size) {
		for (int i = size / 2; i >= 0; i--) {
			heapify(i, size);
		}
	}

	void heapSort() {
		for (int i = heap_.size()-1; i >= 1; i--) {
			std::swap(heap_[0], heap_[i]);
			heapify(0, i);
		}
	}

private:
	std::vector<T> heap_;
};

#endif
