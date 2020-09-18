#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	fstream out;
	out.open("SavingFile.txt");

	ifstream myfile;
	myfile.open("myFile.txt");
	float first = 0;
	float second = 0;
	string str;
	int a = 0;
	float result;
	int count = 0;
	while (!myfile.eof())
	{
		myfile >> str;
		first = stof(str);
		myfile >> str;
		second = stof(str);
		_asm
		{
			finit
			fld first;
			fmul second;
			fstp result;
		}
		cout << "Result is:" << result << endl;


	}
	myfile.close();

	return(0);

}
