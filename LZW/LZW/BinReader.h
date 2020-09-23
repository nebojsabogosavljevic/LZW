#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include "BinReader.h"
using namespace std;
class BinReader
{
public:
	BinReader(string path);
	bool readBit();
	void readByte();
	int readInt16();
	~BinReader();
	ifstream stream;
	int n = 0;
	char character;

};

