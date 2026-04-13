#include <iostream>
#include <Windows.h>
using namespace std;

struct account
{
	int ID;
	string Name;
	float Value;
};

void create_account(account* creating)
{
	cout << "Введите номер счёта: ";
	cin >> creating->ID;
	cout << "Введите имя владельца: ";
	cin >> creating->Name;
	cout << "Введите текущий баланс: ";
	cin >> creating->Value;
}

void change_value(account* Change)
{
	float User_Input;
	cout << "введите новый баланс:";
	cin >> User_Input;
	Change->Value = User_Input;
}

void show_account(account* result)
{
	cout << "Ваш счёт: \n" << "Владелец: " << result->Name << " Номер счёта: " << result->ID << " Текущий баланс: " << result->Value << endl;
}

int main(int argc, char** argv)
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	account User;

	create_account(&User);
	change_value(&User);
	show_account(&User);

	return 0;
}