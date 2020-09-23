#pragma once
#include <iostream>
#include<string>
#include "BinReader.h"
#include <map>
#include <vector>
using namespace std;
class DictionaryDecompress
{
public:
	DictionaryDecompress(string path,int size);
	~DictionaryDecompress();
	BinReader *b;
	int max = 0;
	map<int, string>dic;
	map<string, int>dic2;
	vector<string> result;
	vector<string> num;
	void create(string path1);
};

