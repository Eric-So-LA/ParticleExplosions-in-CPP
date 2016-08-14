//============================================================================
// Name        : Fetching.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int color = 0x12345678;
	//&& means a logical "and" boolean logic
	//& means a bitwise comparison

	//>>16 will shift the bit 4 0's
	unsigned char red = (color & 0xFF000000) >> 24;
	unsigned char blue = (color & 0x00FF0000) >> 16;
	unsigned char green = (color & 0x0000FF00) >> 8;

	cout << hex << (int)red << endl;
	cout << hex << (int)blue << endl;
	cout << hex << green << endl;

	unsigned char redAgain = color >> 24;

	cout << hex << (int)redAgain << endl;
	return 0;
}
