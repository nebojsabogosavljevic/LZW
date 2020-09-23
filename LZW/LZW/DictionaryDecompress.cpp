#include "stdafx.h"
#include "DictionaryDecompress.h"
#include <vector>
#include "BinWriter.h"


DictionaryDecompress::DictionaryDecompress(string path,int size)
{
	b = new BinReader(path);
	for (int i = 0; i < 256; i++)
	{
		char temp = i;
		string t;
		t.push_back(temp);
		dic[i] = t;
		t.clear();
	}

	for (int i = 0; i < 256; i++)
	{
		char temp = i;
		string t;
		t.push_back(temp);
		dic2[t] = i;
		t.clear();
	}

	this->max = size + 256;
}


DictionaryDecompress::~DictionaryDecompress()
{
}



void DictionaryDecompress::create(string path1)
{
	BinWrite *bw=new BinWrite(path1);
	int number = 256;
	vector<int>decode;
	vector<string>lzw;
	int temp = 0;
	string Stemp = "";
	int read = b->readInt16();
	while (b->stream.eof() != true)
	{
		if (b->stream.is_open())
			decode.push_back(read);
		read = b->readInt16();
	}


	int index = decode.at(0);
	result.push_back(dic[index]);
	temp = index;
	Stemp = dic[temp];
	for (int i = 1; i < decode.size(); i++)
	{
		index = decode.at(i);
		string Sindex;
		if (dic.find(index) == dic.end()) {
			Sindex = Stemp[0];
		}
		else {
			Sindex = dic[index];
		}
		 
		if (dic2.find(Stemp + Sindex[0]) == dic2.end())
		{
			if (number != max)
			{
				dic[number] = Stemp + Sindex[0];
				dic2[Stemp + Sindex[0]] = number;
				number++;
				string a = Stemp + Sindex[0];
				num.push_back(a);
			}
		}

		temp = index;
		Stemp = dic[temp];
		result.push_back(dic[index]);
		string p = dic[index];
	}
	string solution = "";
	for (int i = 0; i < result.size(); i++)
	{
		solution = solution + result.at(i);
	}
	for (int i = 0; i < solution.length()+1; i++)
	{
		
		bw->writebyte(solution[i]);
	}

}


