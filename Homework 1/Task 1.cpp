#include <iostream>
#include <Windows.h>
using namespace std;

enum Months 
{
    Close_program,      
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main(int argc, char** argv)
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int user_input;
	bool exit = true;

	do
	{
		cout << "\nВведите номер месяца (для выхода введите 0): ";
		cin >> user_input;
		Months Current = static_cast<Months>(user_input);

		switch (Current)
		{
        default: cout << "\a\nНеверный ввод! только числа от 0 до 12! \n"; break;

        case Close_program: exit = false; cout << "\a"; break;

		case January:   std::cout << "Январь\n"; break;
        case February:  std::cout << "Февраль\n"; break;
        case March:     std::cout << "Март\n"; break;
        case April:     std::cout << "Апрель\n"; break;
        case May:       std::cout << "Май\n"; break;
        case June:      std::cout << "Июнь\n"; break;
        case July:      std::cout << "Июль\n"; break;
        case August:    std::cout << "Август\n"; break;
        case September: std::cout << "Сентябрь\n"; break;
        case October:   std::cout << "Октябрь\n"; break;
        case November:  std::cout << "Ноябрь\n"; break;
        case December:  std::cout << "Декабрь\n"; break;
		}

	} while(exit);

	return 0;
}
