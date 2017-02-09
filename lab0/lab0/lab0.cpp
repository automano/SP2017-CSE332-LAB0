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
#include <sstream>
using namespace std;

int main(int argc, char * argv[])
{
	const int expected_argument_count = 2;
	if (argc == expected_argument_count) // correct arguments (exactly one argument and the program name)
	{
		char * file_name = argv[INPUT_FILE_NAME];
		vector<string> file_content;
		vector<int> file_integer;
		if (ParseFile(file_content, file_name) == SUCCESS)
		{
			cout <<"Non-digit characters: ";
			//differentiate numeric values from other input strings
			for (vector<string>::const_iterator i = file_content.begin(); i != file_content.end(); ++i)
			{ 
				string temp;
				temp = *i;
				int is_not_digit = 0;
				for (int n = 0;n < int(temp.size());n++)
				{
					if (!isdigit(temp[n])) // Adapted from http://www.cplusplus.com/reference/cctype/isdigit/
					{
						is_not_digit++;
					}
				}
				if (is_not_digit == 0)
				{// For each string that contains only numeric digit character
					stringstream ss(temp);
					int x;
					ss >> x;
					file_integer.push_back(x);
				}
				else
				{// For each string that contains any other (non-digit) characters, print the string to the standard output stream.
					
					cout << temp << " ";
				}
			}
			cout << endl<<"Digit characters: ";
			for (vector<int>::const_iterator i = file_integer.begin(); i != file_integer.end(); ++i)
			{
				cout << *i << " ";
			}
			cout << endl;
			return SUCCESS;
		}
		else
		{
			return UNABLE_TO_PARSE_FILE;
		}
	}
	else // wrong arguments number
	{
		char * program_name = argv[PROGRAM_NAME];
		return UsageMessage(program_name);// call usage message 
	}

}

// open a file and read in strings from it
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
		myfile.close(); // END 
		
		return SUCCESS;
	}
	else
	{
		cout << "Open file failed!" << endl;
		return OPEN_FILE_FAILED;
	}
}

// print out uasge message
int UsageMessage(char * program_name)
{
	cout << "usage: "<<program_name <<" <input_file_name>" << endl;
	return WRONG_ARGUMENTS_NUMBER;
}

