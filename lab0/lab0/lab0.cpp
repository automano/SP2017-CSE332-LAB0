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
	const int expected_argument_count = 2;
	if (argc == expected_argument_count) // correct arguments (exactly one argument)
	{
		char * file_name = argv[INPUT_FILE_NAME];
		vector<string> file_content;
		return ParseFile(file_content, file_name);
	}
	else // wrong arguments number
	{
		char * program_name = argv[PROGRAM_NAME];
		return UsageMessage(program_name);// call usage message 
	}

}

int ParseFile(vector<string> &file_content, char *input_file_name)
{// Adapted from http://www.cplusplus.com/doc/tutorial/files/
	ifstream myfile(input_file_name); // Stream class to read from files
	if (myfile.is_open())
	{
		string temp;
		do
		{
			myfile >> temp;
			if(myfile.eof()) break; //adapted from http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line#21666s
			file_content.push_back(temp);
		} while (!myfile.eof());
		myfile.close();
		
		//for (vector<string>::const_iterator i = file_content.begin(); i != file_content.end(); ++i)
			//cout << *i << ' ';

		return SUCCESS;
	}
	else
	{
		cout << "Open file failed!" << endl;
		return OPEN_FILE_FAILED;
	}
}

int UsageMessage(char * program_name)
{
	cout << "usage: "<<program_name <<" <input_file_name>" << endl;
	return WRONG_ARGUMENTS_NUMBER;
}

