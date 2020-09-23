#pragma once
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class BinWrite
{
public:
	BinWrite(string path);
	~BinWrite();
	ofstream p;
	void writebit(bool b);
	void writebyte(char c);
	char character=0;
	int n = 0;
	int num;
    void writeint(int c);

};

