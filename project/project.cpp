#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>

using namespace std;

int main(void)
{

	char file_name[] = "data.txt";
	char buffer[] = "buffer.txt";

	Data var = {};

	cout << "1.Screen input and file recording" << endl;
	cout << "2.Input randomly and write to file" << endl;
	cout << "3.Add an entry to the beginning of the file" << endl;
	cout << "4.Add a record to the end of the file" << endl;
	cout << "5.Printing one record from a file by number" << endl;
	cout << "6.Reading all structures sequentially from a file and printing" << endl;
	cout << "7.Exit the program" << endl;

	while (true)
	{
		int input_number;
		cout << "input number: ";
		cin >> input_number;

		if (input_number != 7)
		{
			switch_function(input_number, var, file_name, buffer);
		}
		else
		{
			break;
		}
	}

	return 0;
}

