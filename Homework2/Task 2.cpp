#include <iostream>
#include <string>
#include <cwctype>
#include <fcntl.h>
#include <io.h>

class Counter
{
private:
    int value;
public:
    Counter() : value(1) {}
    Counter(int initial) : value(initial) {}

    void increment()
    {
        ++value;
    }

    void decrement()
    {
        --value;
    }

    int get_value() const
    {
        return value;
    }
};
void process_commands(Counter& counter)
{
    wchar_t command;
    while (true)
    {
        std::wcout << L"Введите команду ('+', '-', '=' или 'x'): ";
        std::wcin >> command;

        if (command == L'+')
            counter.increment();
        else if (command == L'-')
            counter.decrement();
        else if (command == L'=')
            std::wcout << counter.get_value() << std::endl;
        else if (command == L'x' || command == L'х')
        {
            std::wcout << L"До свидания!" << std::endl;
            break;
        }
        else
            std::wcout << L"Неизвестная команда." << std::endl;
    }
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wstring answer;
    Counter counter; 
    bool valid = false;

    while (true)
    {
        std::wcout << L"Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::wcin >> answer;

        for (wchar_t& c : answer)
            c = std::towlower(static_cast<wchar_t>(c));

        if (answer == L"да")
        {
            int initial;
            std::wcout << L"Введите начальное значение счётчика: ";
            std::wcin >> initial;
            Counter counter_with_initial(initial);
            process_commands(counter_with_initial);
            break; 
        }
        else if (answer == L"нет")
        {
            Counter default_counter;
            process_commands(default_counter);
            break;
        }
        else
        {
            std::wcout << L"Ошибка! Введите 'да' или 'нет' (без учёта регистра)." << std::endl;
        }
    }

    return 0;
}