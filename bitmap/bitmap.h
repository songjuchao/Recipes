#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stdint.h> // uint32_t
#include <string.h> // memset

template<unsigned N>
class Bitmap {
public:
	Bitmap() {
		memset(bitmap, 0, sizeof(bitmap));
	}
	~Bitmap() = default;

	bool setNum(int n) {
		uint32_t index = getIndex(n);
		uint32_t pos = getPos(n);
		if ((bitmap[index] >> pos) & 0x1) {
			return false;
		}

		bitmap[index] |= 0x1 << pos;
		return true;
	}

	bool containsNum(int n) {
		uint32_t index = getIndex(n);
		uint32_t pos = getPos(n);
		return (bitmap[index] >> pos) & 0x1;
	}
private:
	uint32_t getIndex(int n) {
		return n / 32;
	}

	uint32_t getPos(int n) {
		return n % 32;
	}

private:
	uint32_t bitmap[N/32 + 1];
};

#endif
