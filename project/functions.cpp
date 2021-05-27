#define _CRT_SECURE_NO_WARNINGS
#define DEBUG
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>

#define SIZE 2048
#define SIZE_FROM_BUFFER 2048

using namespace std;

int save_rand(char* file_name, Data var)
{
	FILE* fp;

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("CAnt open file");
		return 0;
	}

	fp = fopen(file_name, "a+");

	char array_name[10][15] = { "Bitcoin", "Ethereum", "Tether", "Cardano", "Polkadot", "XRP", "Binance_coin", "Litecoin", "Chainlink", "Stellar" };
	char array_crypto[10][15] = { "BTC", "ETH", "USDT", "ADA", "DOT", "XRP", "BNB", "LTC", "BCH", "LINK" };
	double array_price[10] = { 49213, 1832, 0.99, 0.88, 28, 0.55, 130, 214, 33, 0.5 };
	int array_volume[10] = { 323432421, 123234213, 32152131, 1234213, 35234324, 23454231, 234235423, 234234234, 23425432, 234234234 };

	int random_array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		swap(*(random_array+i), *(random_array + rand() % 10));
	}

	for (int i = 0; i < 10; i++)
	{
		strcpy(var.name, *(array_name + *(random_array + i)));
		strcpy(var.crypto,*(array_crypto + *(random_array + i)));
		var.price = *(array_price + *(random_array + i));
		var.volume = *(array_volume + *(random_array + i));

		fprintf(fp, "%s %s %lf %d\n", var.crypto, var.name, var.price, var.volume);
	}

	fclose(fp);
}

int add_start_file(char* file_name, Data var, char* buffer_data)
{
	FILE* fp;

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("CAnt open file");
		return 0;
	}

	fp = fopen(file_name, "r");
	fp = fopen(file_name, "w+");
	/*fp = fopen(file_name, "a+");*/

	printf("input name: ");
	scanf("%s", &var.crypto);
	printf("input name_2: ");
	scanf("%s", &var.name);
	printf("input price: ");
	scanf("%lf", &var.price);
	printf("input volume: ");
	scanf("%d", &var.volume);
	fprintf(fp, "%s %s %lf %d\n", var.crypto, var.name, var.price, var.volume);

	fclose(fp);
}

void switch_function(int input_number, Data var, char* file_name, char* buffer_data)
{
	FILE* fp, *fp_2;

	int number = 0;

	switch (input_number) {

	case 1:
		add_file_end(file_name, var, buffer_data);
		buffer(file_name, buffer_data);
		break;
	case 2:
		save_rand(file_name, var);
		buffer(file_name, buffer_data);
		break;
	case 3:
		buffer(file_name, buffer_data);
		add_start_file(file_name, var, buffer_data);
		from_buffer(file_name, buffer_data);
		break;
	case 4:
		add_file_end(file_name, var, buffer_data);
		buffer(file_name, buffer_data);
		break;
	case 5:
		printf("input number of line: ");
		scanf("%d", &number);
		getline_number_func(file_name, number);
		break;
	case 6:
		print_console(file_name, var);
		break;
	case 8:
		fp = fopen(file_name, "r");
		fp = fopen(file_name, "w");
		fp_2 = fopen(buffer_data, "r");
		fp_2 = fopen(buffer_data, "w");
		break;
	default:
		break;
	}
}

int buffer(char* data, char* buffer_data) 
{
	size_t num;
	char buffer[SIZE];
	FILE* file_data, * file_buffer;

	if ((file_data = fopen(data, "r")) == NULL)
	{
		printf("can't open file");
		return 1;
	}

	if ((file_buffer = fopen(buffer_data, "w")) == NULL)
	{
		printf("can't open file");
		return 2;
		fclose(file_data);
	}

	while ((num = fread(buffer, sizeof(char), SIZE, file_data)) > 0) // копируем содержимое файла в буфер
	{
		fwrite(buffer, sizeof(char), num, file_buffer);
	}

	fclose(file_data);
	fclose(file_buffer);
	return 0;

}

int from_buffer(char* data, char* buffer_data)
{
	size_t num;
	char buffer_2[SIZE_FROM_BUFFER];
	FILE* file_data, * file_buffer;

	if ((file_buffer = fopen(data, "r")) == NULL)
	{
		printf("can't open file");
		return 1;
	}

	if ((file_data = fopen(buffer_data, "a+")) == NULL)
	{
		printf("can't open file");
		return 2;
		fclose(file_data);
	}

	file_buffer = fopen(buffer_data, "r");

	file_data = fopen(data, "a+");


	while ((num = fread(buffer_2, sizeof(char), SIZE, file_buffer)) > 0) // копируем содержимое файла в буфер
	{
		fwrite(buffer_2, sizeof(char), num, file_data);
	}

	fclose(file_data);
	fclose(file_buffer);
	return 0;
}

int print_console(char* file_name, Data var) 
{
	Data line;
	FILE* f = fopen(file_name, "r");
	int c = 0;
	while (!feof(f))
	{
		fscanf(f, "%s %s %lf %d", &line.crypto, &line.name, &line.price, &line.volume);
		printf("(%s) (%s) ||%lf|| ||%d||\n", line.crypto, line.name, line.price, line.volume);
	}

	fclose(f);

	return 1;
}

int getline_number_func(char* file_name, int number_line)
{

	Data line;
	FILE* f = fopen(file_name, "r");
	int c = 0;
	while (!feof(f))
	{
		c++;
		fscanf(f, "%s %s %lf %d", &line.crypto, &line.name, &line.price, &line.volume);
		if (c == number_line)
		{
			printf("(%s) (%s) ||%lf|| ||%d||\n", line.crypto, line.name, line.price, line.volume);
			break;
		}
		else
		{
			continue;
		}
	}

	fclose(f);

	return 1;
}

int add_file_end(char* file_name, Data var, char* buffer_data)
{
	FILE* fp;

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("CAnt open file");
		return 0;
	}

	fp = fopen(file_name, "r");
	fp = fopen(file_name, "a+");

	printf("input name: ");
	scanf("%s", &var.crypto);
	printf("input name_2: ");
	scanf("%s", &var.name);
	printf("input price: ");
	scanf("%lf", &var.price);
	printf("input volume: ");
	scanf("%d", &var.volume);
	fprintf(fp, "(%s) (%s) ||%lf|| ||%d||\n", var.crypto, var.name, var.price, var.volume);

	fclose(fp);
}