#include <iostream>
#include <limits>

class Calculator 
{
private:
    double num1;
    double num2;

public:
    Calculator() : num1(1.0), num2(1.0) {}

    double add() const 
    {
        return num1 + num2;
    }
    double subtract_1_2() const 
    {
        return num1 - num2;
    }
    double subtract_2_1() const 
    {
        return num2 - num1;
    }
    double multiply() const
    {
        return num1 * num2;
    }
    double divide_1_2() const 
    {
        return num1 / num2;
    }
    double divide_2_1() const 
    {
        return num2 / num1;
    }
    bool set_num1(double value) 
    {
        if (value != 0.0) 
        {
            num1 = value;
            return true;
        }
        return false;
    }
    bool set_num2(double value) 
    {
        if (value != 0.0) 
        {
            num2 = value;
            return true;
        }
        return false;
    }
};

double Input_Check(const std::string& input) 
{
    double value;
    while (true) {
        std::cout << input;
        std::cin >> value;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите число.\n";
            continue;
        }

        if (value == 0.0) 
        {
            std::cout << "Ошибка: число не должно быть равно 0.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

int main() 
{
    Calculator calc;
    double a, b;

    std::cout << "Калькулятор запущен. Для выхода закройте консоль.\n";

    while (true) 
    {
        double a = Input_Check("Введите первое число: ");
        double b = Input_Check("Введите второе число: ");

        bool ok1 = calc.set_num1(a);
        bool ok2 = calc.set_num2(b);

        if (ok1 && ok2) 
        {
            std::cout << "Результаты:\n";
            std::cout << "num1 + num2: " << calc.add() << '\n';
            std::cout << "num1 - num2: " << calc.subtract_1_2() << '\n';
            std::cout << "num2 - num1: " << calc.subtract_2_1() << '\n';
            std::cout << "num1 * num2: " << calc.multiply() << '\n';
            std::cout << "num1 / num2: " << calc.divide_1_2() << '\n';
            std::cout << "num2 / num1: " << calc.divide_2_1() << '\n';
        }
    }

    return 0;
}