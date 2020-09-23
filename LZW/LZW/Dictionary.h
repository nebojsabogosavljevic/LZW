#pragma once
#include "BinReader.h"
#include <iostream>
#include <string>
#include <map>
#include<vector>
using namespace std;
class Dictionary

{
public:
	Dictionary(string path,int size);
	~Dictionary();
	BinReader *br;
	void create();
	int max = 0;
	map<string, int>dic;
	vector<string> result;
};

