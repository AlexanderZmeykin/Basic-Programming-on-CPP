#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

class Fraction 
{
private:
    int numerator;   // числитель
    int denominator; // знаменатель (всегда >0 после нормализации)

    // Нахождение наибольшего общего делителя (алгоритм Евклида)
    static int gcd(int a, int b) 
    {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Приведение дроби к каноническому виду:
    // - знаменатель > 0
    // - дробь несократима (числитель и знаменатель делятся на НОД)
    void reduce() 
    {
        if (denominator == 0) 
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        // Перенос знака в числитель(т.н. нормализация)
        if (denominator < 0) 
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    // Конструктор, сразу приводит дробь к несократимому виду
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) 
    {
        reduce();
    }

    // Формат "числитель/знаменатель" специально для тестов
    std::string dump() const 
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // Операторы сравнения 
    // Приводим к общему знаменателю чтобы сравнивать. Можно было оставить int, но long long больше подходит, если у нас будут большие значения
    friend bool operator==(const Fraction& lhs, const Fraction& rhs) 
    {
        return static_cast<long long>(lhs.numerator) * rhs.denominator ==
            static_cast<long long>(rhs.numerator) * lhs.denominator;
    }

    friend bool operator!=(const Fraction& lhs, const Fraction& rhs) 
    {
        return !(lhs == rhs);
    }

    friend bool operator<(const Fraction& lhs, const Fraction& rhs) 
    {
        return static_cast<long long>(lhs.numerator) * rhs.denominator <
            static_cast<long long>(rhs.numerator) * lhs.denominator;
    }

    friend bool operator>(const Fraction& lhs, const Fraction& rhs) 
    {
        return rhs < lhs;
    }

    friend bool operator<=(const Fraction& lhs, const Fraction& rhs) 
    {
        return !(lhs > rhs);
    }

    friend bool operator>=(const Fraction& lhs, const Fraction& rhs) 
    {
        return !(lhs < rhs);
    }

    // Арифметические операторы 
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) 
    {
        int new_num = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
        int new_den = lhs.denominator * rhs.denominator;
        return Fraction(new_num, new_den);
    }

    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) 
    {
        int new_num = lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator;
        int new_den = lhs.denominator * rhs.denominator;
        return Fraction(new_num, new_den);
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) 
    {
        int new_num = lhs.numerator * rhs.numerator;
        int new_den = lhs.denominator * rhs.denominator;
        return Fraction(new_num, new_den);
    }

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) 
    {
        if (rhs.numerator == 0) {
            throw std::invalid_argument("Division by zero");
        }
        int new_num = lhs.numerator * rhs.denominator;
        int new_den = lhs.denominator * rhs.numerator;
        return Fraction(new_num, new_den);
    }

    // Унарный минус
    Fraction operator-() const 
    {
        return Fraction(-numerator, denominator);
    }

    // Инкремент / декремент (увеличение/уменьшение на целое число 1)
    // Префиксный ++fraction
    Fraction& operator++() 
    {
        numerator += denominator;   // добавляем 1 = denominator/denominator
        reduce();
        return *this;
    }

    // Постфиксный fraction++
    Fraction operator++(int) 
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    // Префиксный --fraction
    Fraction& operator--() 
    {
        numerator -= denominator;   // вычитаем 1
        reduce();
        return *this;
    }

    // Постфиксный fraction--
    Fraction operator--(int) 
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
};

// Юнит-тесты
int main() 
{
    // Тест 0: тест с ручным выводом результата в консоль
    Fraction f1(4, 3);
    Fraction f2(6, 11);
    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << "\n";
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << "\n";
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << "\n";
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << "\n";
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << "\n";
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << "\n";

    // Тест 1: Проверка конструкторов и dump
    {
        Fraction f1(3, 4);
        Fraction f2(4, 5);
        assert(f1.dump() == "3/4");
        assert(f2.dump() == "4/5");
    }

    // Тест 2: Проверка неравенства    
    // Вообще, это то эе самое, что и нулевой тест, но раз уж в задании они прописаны так, значит, будут так.
    {
        Fraction f1(4, 3);
        Fraction f2(6, 11);
        assert(!(f1 == f2));
        assert(f1 != f2);
        assert(!(f1 < f2));
        assert(f1 > f2);
        assert(!(f1 <= f2));
        assert(f1 >= f2);
    }

    // Тест 3: Проверка равенства    
    {
        Fraction f1(4, 3);
        Fraction f2(8, 6);
        assert(f1 == f2);
        assert(!(f1 != f2));
        assert(!(f1 < f2));
        assert(!(f1 > f2));
        assert(f1 <= f2);
        assert(f1 >= f2);
    }

    // Тест 4: Проверка сценария    
    {
        Fraction f1(3, 4);
        Fraction f2(4, 5);
        assert((f1 + f2).dump() == "31/20");
        assert((f1 - f2).dump() == "-1/20");
        assert((f1 * f2).dump() == "3/5");
        assert((f1 / f2).dump() == "15/16");
        assert((++f1 * f2).dump() == "7/5");
        assert(f1.dump() == "7/4");
        assert((f1-- * f2).dump() == "7/5");
        assert(f1.dump() == "3/4");
    }

    // Тест 5: Дополнительные проверки с унарным минусом    
    {
        Fraction f1(2, 3);
        Fraction f2(-2, 3);
        assert((-f1).dump() == "-2/3");
        assert((-f2).dump() == "2/3");
        assert((-f1) == f2);
    }

    // Тест 6: Проверка сокращения дробей    
    {
        Fraction f1(4, 8);
        Fraction f2(2, 4);
        Fraction f3(1, 2);
        assert(f1.dump() == "1/2");
        assert(f2.dump() == "1/2");
        assert(f3.dump() == "1/2");
        assert(f1 == f2);
        assert(f2 == f3);
    }

    // Тест 7: Проверка с отрицательными дробями    
    {
        Fraction f1(-3, 4);
        Fraction f2(3, -4);
        Fraction f3(-3, -4);
        assert(f1.dump() == "-3/4");
        assert(f2.dump() == "-3/4");
        assert(f3.dump() == "3/4");
        assert(f1 == f2);
        assert(f1 != f3);
    }

    std::cout << "Все тесты пройдены успешно!" << std::endl;
    return 0;
}