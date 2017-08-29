#include <iostream>

#include "bitmap.h"

void unitTest() {
	Bitmap<128> bitmap;
	std::cout << "setNum(127) is " << bitmap.setNum(127) << std::endl;
}

int main() {
	unitTest();
}
