#include "stdafx.h"
#include "Dictionary.h"
#include <vector>
#include "BinWriter.h"


Dictionary::Dictionary(string path,int size)
{
	br = new BinReader(path);
	for (int i = 0; i < 256; i++)
	{
		char temp = i;
		string t;
		t.push_back(temp);
		dic[t] = i;
		t.clear();
	}
	this->max = size + 256;
	create();
}


Dictionary::~Dictionary()
{
}

void Dictionary::create()
{
	BinWrite bw("out.bin");
	char character;
	int number = 256;
	string temp = "";
	bool t = false;
	vector <string> lzw;
	while (br->stream.eof() == false)
	{
		br->readByte();
		character = br->character;
		if (br->stream.is_open())
		{
			if (dic.find(temp + character) == dic.end())
			{
				if (number != max)
				{
					dic[temp + character] = number;
					number++;
					result.push_back(temp + character);
				}
				
				lzw.push_back(temp);
				temp = character;
			}
			else
			{
				temp = temp + character;
			}
		}
	}
	lzw.push_back(temp);
	for (int i = 0; i < lzw.size(); i++)
	{
		bw.writeint(dic[lzw.at(i)]);
	}
}
