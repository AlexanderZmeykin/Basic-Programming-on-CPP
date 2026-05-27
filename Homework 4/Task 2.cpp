#include <iostream>
#include <string>

class Figure 
{
public:
    virtual ~Figure() = default;
    virtual void print_info() const = 0;
};

class Triangle : public Figure 
{
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    void print_info() const override 
    {
        std::cout << "Треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class Right_Triangle : public Triangle 
{
public:
    Right_Triangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {}

    void print_info() const override 
    {
        std::cout << "Прямоугольный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class Isosceles_Triangle : public Triangle 
{
public:
    Isosceles_Triangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}

    void print_info() const override 
    {
        std::cout << "Равнобедренный треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class Equilateral_Triangle : public Triangle 
{
public:
    Equilateral_Triangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override 
    {
        std::cout << "Равносторонний треугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class Quadrilateral : public Figure 
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d,
                  double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    void print_info() const override 
    {
        std::cout << "Четырёхугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Parallelogram : public Quadrilateral 
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override 
    {
        std::cout << "Параллелограмм:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Rectangle : public Parallelogram 
{
public:
    Rectangle(double a, double b)
        : Parallelogram(a, b, 90, 90) {}

    void print_info() const override 
    {
        std::cout << "Прямоугольник:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Rhombus : public Parallelogram 
{
public:
    Rhombus(double a, double A, double B)
        : Parallelogram(a, a, A, B) {}

    void print_info() const override 
    {
        std::cout << "Ромб:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Square : public Rectangle 
{
public:
    Square(double a) : Rectangle(a, a) {}

    void print_info() const override 
    {
        std::cout << "Квадрат:\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

void print_info(Figure* figure) 
{
    figure->print_info();
}

int main() 
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_Triangle right_triangle(10, 20, 30, 30, 60);
    Isosceles_Triangle isosceles_triangle(10, 20, 50, 60);
    Equilateral_Triangle equilateral_triangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_info(&triangle);
    std::cout << "\n";
    print_info(&right_triangle);
    std::cout << "\n";
    print_info(&isosceles_triangle);
    std::cout << "\n";
    print_info(&equilateral_triangle);
    std::cout << "\n";
    print_info(&quadrilateral);
    std::cout << "\n";
    print_info(&rectangle);
    std::cout << "\n";
    print_info(&square);
    std::cout << "\n";
    print_info(&parallelogram);
    std::cout << "\n";
    print_info(&rhombus);

    return 0;
}