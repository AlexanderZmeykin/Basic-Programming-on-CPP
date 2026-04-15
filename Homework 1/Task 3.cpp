#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

struct account
{
	wstring City;
	wstring Street;
	wstring House;
	int Apartment;
	int Index;
};

void create_account(account* creating, int i)
{
	wcout << L"Введите город: ";
	wcin >> creating[i].City;
	wcout << L"Введите улицу: ";
	wcin >> creating[i].Street;
	wcout << L"Введите дом: ";
	wcin >> creating[i].House;
	wcout << L"Введите номер квартиры: ";
	wcin >> creating[i].Apartment;
	wcout << L"Введите почтовый индекс: ";
	wcin >> creating[i].Index;
	wcout << L"\n";
}

void show_account(account* result, int j)
{
	int Num = j + 1;
	wcout << L"\nАдрес №" << Num << ": \n" << L"Город: " << result[j].City << L"\nУлица:" << result[j].Street << L"\nДом:" << result[j].House 
		<< L"\nНомер квартиры:" << result[j].Apartment << L"\nПочтовый индекс:" << result[j].Index << L"\n==================================================";
}

int main(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	int Value;
	wcout << L"Введите число экземпляров: ";
	wcin >> Value;
	account* User = new account[Value];

	for (int i{ 0 }; i < Value; i++)
	{
		create_account(User, i);
	}
	for (int j{ 0 }; j < Value; j++)
	{
		show_account(User, j);
	}
	
	return 0;
}