#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define DEBUG

struct Data
{
	char crypto[30];
	char name[30];
	double price;
	int volume;
};

int save_rand(char* file_name, Data var);

int add_start_file(char* file_name, Data var, char* buffer_data);

void switch_function(int input_number, Data var, char* file_name, char* buffer_data);

int buffer(char* data, char* buffer_data);

int from_buffer(char* data, char* buffer_data);

int print_console(char* file_name, Data var);

int getline_number_func(char * file_name, int number_line);

int add_file_end(char* file_name, Data var, char* buffer_data);

#endif