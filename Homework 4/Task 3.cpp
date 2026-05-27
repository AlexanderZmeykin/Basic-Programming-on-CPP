#include <iostream>
#include <vector>
#include <cmath>

class Figure 
{
protected:
    int sides_count;

public:
    Figure(int sides) : sides_count(sides) {}
    virtual ~Figure() = default;

    virtual bool check() const 
    {
        return true;
    }

    void print_common() const 
    {
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
    }

    virtual void print_info() const 
    {
        std::cout << "Фигура:" << std::endl;
        print_common();
    }
};

class Triangle : public Figure 
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure(3), a(a), b(b), c(c), A(A), B(B), C(C) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return sides_count == 3 && std::fabs(A + B + C - 180.0) < eps;
    }

    void print_sides() const 
    {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
    }

    void print_angles() const 
    {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    void print_info() const override 
    {
        std::cout << "Треугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Right_Triangle : public Triangle 
{
public:
    Right_Triangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90.0) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Triangle::check() && std::fabs(C - 90.0) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Прямоугольный треугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Isosceles_Triangle : public Triangle 
{
public:
    Isosceles_Triangle(double a, double b, double c, double A, double B, double C)
        : Triangle(a, b, c, A, B, C) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Triangle::check() && std::fabs(a - c) < eps && std::fabs(A - C) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Равнобедренный треугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Equilateral_Triangle : public Triangle 
{
public:
    Equilateral_Triangle(double side)
        : Triangle(side, side, side, 60.0, 60.0, 60.0) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Triangle::check() &&
               std::fabs(a - b) < eps && std::fabs(b - c) < eps &&
               std::fabs(A - 60.0) < eps && std::fabs(B - 60.0) < eps && std::fabs(C - 60.0) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Равносторонний треугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Quadrilateral : public Figure 
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : Figure(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return sides_count == 4 && std::fabs(A + B + C + D - 360.0) < eps;
    }

    void print_sides() const 
    {
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    }

    void print_angles() const 
    {
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    void print_info() const override 
    {
        std::cout << "Четырёхугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Rectangle : public Quadrilateral 
{
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90.0, 90.0, 90.0, 90.0) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Quadrilateral::check() &&
               std::fabs(a - c) < eps && std::fabs(b - d) < eps &&
               std::fabs(A - 90.0) < eps && std::fabs(B - 90.0) < eps &&
               std::fabs(C - 90.0) < eps && std::fabs(D - 90.0) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Прямоугольник:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Square : public Rectangle 
{
public:
    Square(double side) : Rectangle(side, side) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Rectangle::check() && std::fabs(a - b) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Квадрат:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Parallelogram : public Quadrilateral 
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Quadrilateral::check() &&
               std::fabs(a - c) < eps && std::fabs(b - d) < eps &&
               std::fabs(A - C) < eps && std::fabs(B - D) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Параллелограмм:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

class Rhombus : public Parallelogram 
{
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B) {}

    bool check() const override 
    {
        const double eps = 1e-9;
        return Parallelogram::check() && std::fabs(a - b) < eps;
    }

    void print_info() const override 
    {
        std::cout << "Ромб:" << std::endl;
        print_common();
        print_sides();
        print_angles();
    }
};

int main() 
{
    Figure figure(0);
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_Triangle right1(10, 20, 30, 50, 60);   // неправильный (сумма углов 200)
    Right_Triangle right2(10, 20, 30, 60, 30);   // правильный (50+40+90=180)
    Isosceles_Triangle isosceles(10, 20, 10, 50, 60, 50); // неправильный (сумма 160)
    Equilateral_Triangle equilateral(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80); // сумма 260
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40); // сумма углов 140
    Rhombus rhombus(30, 30, 40);                 // сумма углов 140

    std::vector<Figure*> figures = 
    {
        &figure, &triangle, &right1, &right2, &isosceles,
        &equilateral, &quadrilateral, &rectangle, &square,
        &parallelogram, &rhombus
    };

    for (auto* fig : figures) 
    {
        fig->print_info();
        std::cout << std::endl;
    }

    return 0;
}