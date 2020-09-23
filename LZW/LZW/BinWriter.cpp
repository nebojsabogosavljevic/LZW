#include "stdafx.h"
#include "BinWriter.h"


BinWrite::BinWrite(string path)
{
	p.open(path, std::ios::binary);
}


BinWrite::~BinWrite()
{
	if (n>0)
	p.write(&character, 1);
	p.close();
}

void BinWrite::writebit(bool b)
{
	if (n == 8)
	{
		p.write(&character, 1);
		n = 0;
		character = 0;
	}
	character ^= (-b ^ character) & (1 << n);
	n++;
}

void BinWrite::writebyte(char c)
{
	for (int i = 0; i < 8; i++)
	{
		bool b = (c >> i) & 1;
		writebit(b);
	}
}

void BinWrite::writeint(int c)
{
	string result = "";
	for (int i = 0; i < 16; i++)
	{
		bool b = (c >> i) & 1;
		writebit(b);
	}
}