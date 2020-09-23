#include "stdafx.h"
#include "BinReader.h"


BinReader::BinReader(string path)
{
	stream.open(path, std::ios::binary);
	stream.read(&character, 1);
}

bool BinReader::readBit()
{
	bool b;
	if (n == 8) {
		stream.read(&character, 1);
		n = 0;
	}
	b = (character >> n) & 1;
	n++;
	return b;
}

void BinReader::readByte()
{
		char c = 0;
		if (stream.is_open())
		{
			for (int i = 0; i < 8; i++)
			{
				if (this->readBit() && this->stream.eof() == false)
					c += pow(2, i);
			}
		}
		if (this->stream.eof() == true)
		{
			stream.close();
		}

}

int BinReader::readInt16()
{
	short int c = 0;
	if (stream.is_open())
	{
		for (int i = 0; i < 16; i++)
		{
			if (this->readBit() && this->stream.eof() == false)
				c += pow(2, i);
		}
	}
	return c;
	if (this->stream.eof() == true)
	{
		stream.close();
	}

}

BinReader::~BinReader()
{
}
