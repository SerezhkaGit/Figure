#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double calculateArea() const = 0; // Чисто віртуальна функція
};


class Triangle : public Shape 
{
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override 
    {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape 
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }
};


int main() 
{
    Triangle triangle(5, 3);
    Circle circle(4);
    Rectangle rectangle(6, 8);

    const Shape* shapes[] = { &triangle, &circle, &rectangle };
    double totalArea = 0.0;

    for (const auto& shape : shapes) {
        totalArea += shape->calculateArea();
    }

    cout << "Total area of all shapes: " << totalArea << std::endl;

    return 0;
}
