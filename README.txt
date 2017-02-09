// Name and Student ID
Zhening Li 445612

// Lab Number
Lab 0

// Purpose
a simple C++ program that can (1) read in and parse command line arguments, 
(2) open a file and read in strings from it, 
(3) differentiate numeric values from other input strings, and 
(4) produce output based on the strings that it read in, to the standard output stream.

// Warnings
// #1
warning C4018: '<': signed/unsigned mismatch
for (int n = 0;n < temp.size();n++)

solution:
for (int n = 0;n < int(temp.size());n++)

// Error
// #1
Reading from text file until EOF repeats last line.  
Uses a ifstream object to read integers from a text file (which has one number per line) until it hits EOF. 
But it read the content on the last line twice.

solution:
http://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line#21666

// test

// #1. bad format input - wrong argument
lab0.exe 
// #1. output
usage: lab0.exe <input_file_name>
// echo %errorlevel%
3

// #2. bad format input - wrong file name
lab0.exe in 
// #2. output
Open file failed!
// echo %errorlevel%
2

// #3. correct input
lab0.exe input_file.txt
// #3. output
Non-digit characters: these all are strings 7string str4ing string2
Digit characters: 0 1 2 3 5 7 11 13 17 19
// echo %errorlevel%
0


// Extra Credit

// command prompt

SSH Secure Shell 3.2.9 (Build 283)
Copyright (c) 2000-2003 SSH Communications Security Corp - http://www.ssh.com/

This copy of SSH Secure Shell is a non-commercial version.
This version does not include PKI and PKCS #11 functionality.


Last failed login: Sat Feb  4 12:59:17 CST 2017 from rdsh1.seas.wustl.edu on ssh:notty
There was 1 failed login attempt since the last successful login.
Last login: Sat Feb 20 13:36:48 2016 from rdp-srv1.seasad.wustl.edu
##### ATTENTION #####

shell.cec is no longer suited for
computationally-heavy tasks.

Please use 'qlogin' to obtain a
terminal on one of the LinuxLab
hosts.

Thank you!

EIT

#####
[zhening.li@shell ~]$

// Results of these trials

[zhening.li@shell lab0]$ ./lab0.exe
usage: ./lab0.exe <input_file_name>
[zhening.li@shell lab0]$ ./lab0.exe input_file.txt 
Non-digit characters: these all are strings 7string str4ing string2 
Digit characters: 0 1 2 3 5 7 11 13 17 19 
[zhening.li@shell lab0]$ 




