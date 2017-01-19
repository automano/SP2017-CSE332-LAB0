// lab0.cpp
// Author: Zhening Li E-mail:zhening.li@wustl.edu
// Purpose: Lab0 main program entrance point


#include "stdafx.h"
#include "Header.h"
#include "lab0.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char * argv[])
{
	char * file_name = argv[INPUT_FILE_NAME];
	vector<string> file_content;
	ParseFile(file_content, file_name);
	return SUCCESS;
}

int ParseFile(vector<string> &file_content, char *input_file_name)
{
	ifstream myfile(input_file_name); // Stream class to read from files
	if (myfile.is_open())
	{
		string line;
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		cout << "Open file failed!" << endl;
		return OPEN_FILE_FAILED;
	}
}

