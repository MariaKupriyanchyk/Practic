//использовать стандартные функции обработки строк на си:
//strtok, strtol, strof(atoi, itoa), strcat(strncat), strcpy(strncpy), strcmp(strncmp), strstr, strpbrk.
//на лексемы разбивать строку типа char* функцией strtok, лексемы сохранить в массив строк.
//использовать string (c++ stl), методы: insert, erase, c_str, find, find_last…, find_fist…, reverse, compare, +(объединение строк).
//преобразование строки из (в) char* в (из) string.
//данные для индивидуальных задач - считать из файла и записать в файл.
//
//6.9 программа, которая запрашивает у пользователя 2 строки.
//вторая строка содержит разделители.
//для сhar строк: разбивает первую строку на лексемы,
//определяет в ней лексемы - целые числа в 2-й с\с, и подсчитывает число лексем, состоящих только из единиц,
//формирует из найденных групп лексем новую строку (лексемы в строках разделяются пробелом).
//сортирует одну из строк методом "пузырька".
//для string строк: преобразовать первую строку в строку типа string.
//дублирует в строке типа string любое число 2 с\с. удаляет из string первую лексему. результаты выводит в файл.

//добавить:
//перевод из string в char;
//научиться использовать функции strtol, strof(atoi, itoa).

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;

bool OnlyOnes(const char* token)
{
    while (*token) 
	{
        if (*token != '1') return false;
        token++;
    }
    return true;
}

bool OnlyZeros(const char* token)
{
	while (*token)
	{
		if (*token != '0') return false;
		token++;
	}
	return true;
}

bool OnesAndZeros(const char* token)
{
	while (*token)
	{
		if ((*token != '0') && (*token != '1')) return false;
		token++;
	}
	return true;
}

int main(/*int argc, char* argv[]*/) 
{
	setlocale(LC_ALL, "ru");

	ifstream inputfile("input.txt");
	ofstream outputfile("output.txt");

	if (!inputfile || !outputfile)
	{
		cerr << "Ошибка открытия файла" << endl;
		return 1;
	}

	int const max_size = 256;
	char str_char[max_size];
	inputfile.getline(str_char, max_size);
	char str_delimiters[max_size];
	inputfile.getline(str_delimiters, max_size);
	string str_string(str_char);

	outputfile << "Работа со строками char" << endl;
	char* lexemes[max_size];
	int number_of_tokens1 = 0, number_of_tokens2 = 0, number_of_ones = 0;
	char* token = strtok(str_char, str_delimiters);
	char* str_of_binary_system_numbers[max_size];
	while (token != NULL && number_of_tokens1 < max_size)
	{
		lexemes[number_of_tokens1++] = token;
		if(OnlyOnes(token) || OnlyZeros(token) || OnesAndZeros(token))
		{
			str_of_binary_system_numbers[number_of_tokens2++] = token;
		}
		if (OnlyOnes(token))
		{
			number_of_ones++;
		}
		token = strtok(NULL, str_delimiters);
	}

	outputfile << "Вывод всех лексем первой строки: " << endl;
	for (int i = 0; i < number_of_tokens1; i++)
	{
		outputfile << lexemes[i] << " ";
	}
	outputfile << endl;

	outputfile << "Вывод всех чисел в двоичной системе из первой строки: " << endl;
	for (int i = 0; i < number_of_tokens2; i++)
	{
		outputfile << str_of_binary_system_numbers[i] << " ";
	}
	outputfile << endl;

	outputfile << "Количество чисел, состоящих только из единиц: " << endl;
	outputfile << number_of_ones << endl;

	for (int i = 0; i < number_of_tokens2 - 1; i++)
	{
        for (int j = 0; j < number_of_tokens2 - i - 1; j++)
		{
            if (strcmp(str_of_binary_system_numbers[j], str_of_binary_system_numbers[j + 1]) > 0)
			{
                swap(str_of_binary_system_numbers[j], str_of_binary_system_numbers[j + 1]);
            }
        }
    }
	outputfile << "Вывод отсортированной по возрастанию строки, состоящей из чисел двоичной системы: " << endl;
	for (int i = 0; i < number_of_tokens2; i++)
	{
		outputfile << str_of_binary_system_numbers[i] << " ";
	}
	outputfile << endl;
	outputfile << endl;

	outputfile << "Работа со строками string" << endl;
	string tempstr = str_string;
	size_t start = 0;
	size_t end = tempstr.find_first_of(str_delimiters);
	string tokenstr[max_size];
	int token_count = 0;

	while (end != string::npos)
	{
		if (start != end)
		{
			tokenstr[token_count++] = tempstr.substr(start, end - start); // Получаем лексему
		}
		start = end + 1;
		end = tempstr.find_first_of(str_delimiters, start);
	}

	// Добавляем последнюю лексему
	if (start < tempstr.length()) 
	{
		tokenstr[token_count++] = tempstr.substr(start);
	}

	// Выводим лексемы
	outputfile << "Вывод строки string, поделеной на лексемы:" << endl;
	for (int i = 0; i < token_count; ++i) 
	{
		outputfile << tokenstr[i] << " ";
	}
	outputfile << endl;

	string result;
	for (size_t i = 0; i < token_count; i++)
	{
		if (tokenstr[i].find('0') != -1 || tokenstr[i].find('1') != -1)
		{
			result += tokenstr[i];
			result += tokenstr[i];
			result += " ";
		}
		else
		{
			result += tokenstr[i];
			result += " ";
		}
	}

	//удаление первой лексемы
    size_t firstspace = result.find(' ');
    if (firstspace != string::npos)
	{
        result.erase(0, firstspace + 1);
    }
	else 
	{
		result.clear();
	}

	outputfile << "Преобразованная строка string, в которой удалили первую лексему и продублировали двоичные числа:" << endl;
	outputfile << result << endl;

	inputfile.close();
	outputfile.close();

	//Для проверки: 10i+10010+1+0+jk2j 111+1 kw+ 01l

	cout << "Результаты программы выведены в файл";
	return 0;
}