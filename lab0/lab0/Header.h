// Header.h
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: Declare an enumeration for the different array indices that are relevant to my program
//          Declare an enumeration for the different success and failure values my program
#pragma once

enum ArrayIndices
{
	PROGRAM_NAME,
	INPUT_FILE_NAME,
	CDM_ARGUMENTS_NUMBER
};

enum ProgramStatus
{
	SUCCESS,
	OPEN_FILE_FAILED,
	WRONG_ARGUMENTS_NUMBER
};
