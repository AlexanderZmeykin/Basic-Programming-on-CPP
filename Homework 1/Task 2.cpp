#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

using namespace std;

struct account
{
	int ID;
	wstring Name;
	float Value;
};

void create_account(account* creating)
{
	wcout << L"Введите номер счёта: ";
	wcin >> creating->ID;
	wcout << L"Введите имя владельца: ";
	wcin >> creating->Name;
	wcout << L"Введите текущий баланс: ";
	wcin >> creating->Value;
}

void change_value(account* Change)
{
	float User_Input;
	wcout << L"введите новый баланс:";
	wcin >> User_Input;
	Change->Value = User_Input;
}

void show_account(account* result)
{
	wcout << L"Ваш счёт: \n" << L"Владелец: " << result->Name << L" Номер счёта: " << result->ID << L" Текущий баланс: " << result->Value << endl;
}

int main(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);

	account User;

	create_account(&User);
	change_value(&User);
	show_account(&User);

	return 0;
}