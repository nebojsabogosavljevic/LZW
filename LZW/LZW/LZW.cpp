// LZW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include "BinWriter.h"
#include "DictionaryDecompress.h"
#include <fstream>
//int main()
//{
//	
//Dictionary d1("giphy.gif", 1000);
//DictionaryDecompress d2("out.bin", 1000);
//d2.create("in.bin");
//system("pause");
// return 0;
//}

int main(int argc, char* argv[])
{
	string path = string(argv[4]);
	int maxnumber = stoi(argv[3]);
	string option = string(argv[2]);
	if (option == "c" || option == "C")
	{
		Dictionary d1(path, maxnumber);
	}
	else if (option == "d" || option == "D")
	{
		DictionaryDecompress d2(path, maxnumber);
		d2.create("out_dec.bin");
	}
	else
	{
		cout << "Wrong entry";
	}
	system("pause");
	return 0;
}