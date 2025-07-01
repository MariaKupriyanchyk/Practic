#include "circle.h"
#include <iostream>
#include <cmath>

double x;
double y;
double radius;

Circle:: Circle(double x, double y, double radius)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

Circle:: Circle()
    {
        x = 0;
        y = 0;
        radius = 1;
    }

Circle:: ~Circle() {}

Circle:: Circle(const Circle& other)
    {
        this->x = other.x;
        this->y = other.y;
        this->radius = other.radius;
    }

    void Circle::print()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "radius = " << radius << endl;
        cout << endl;
    }

    double Circle::area() const
    {
        return PI * radius * radius;
    }

    Circle operator+(const Circle& a, const Circle& b)
    {
        return Circle(a.x + b.x, a.y + b.y, a.radius + b.radius);
    }

    Circle operator-(const Circle& a, const Circle& b)
    {
        return Circle(a.x - b.x, a.y - b.y, max(0.0, a.radius - b.radius));
    }

    Circle operator*(const Circle& c, double n)
    {
        return Circle(c.x, c.y, c.radius * n);
    }

    Circle operator/(const Circle& c, double n)
    {
        return Circle(c.x, c.y, c.radius / n);
    }

    Circle Circle:: operator~()
    {
        return Circle(-x, -y, radius);
    }

    Circle Circle:: operator++()
    {
        x += 1;
        y += 1;
        radius += 1;

        return *this;
    }

    Circle Circle:: operator--()
    {
        x -= 1;
        y -= 1;
        radius -= 1;

        return *this;
    }

    Circle Circle:: operator++(int)
    {
        Circle temp(*this);
        this->x += 1;
        this->y += 1;
        this->radius += 1;

        return temp;
    }

    Circle Circle:: operator--(int)
    {
        Circle temp(*this);
        this->x -= 1;
        this->y -= 1;
        this->radius -= 1;

        return temp;
    }

    bool Circle:: operator<(const Circle& other)
    {
        return area() < other.area();
    }

    bool Circle:: operator>(const Circle& other)
    {
        return area() > other.area();
    }

    bool Circle:: operator<=(const Circle& other) const
    {
        return !(area() > other.area());
    }

    bool Circle:: operator>=(const Circle& other) const
    {
        return !(area() < other.area());
    }

    Circle& Circle:: operator=(const Circle& other)
    {
        if (this != &other)
        {
            x = other.x;
            y = other.y;
            radius = other.radius;
        }
        return *this;
    }

    bool Circle:: operator==(const Circle& other) const
    {
        return (x == other.x) && (y == other.y) && (radius == other.radius);
    }

    bool Circle:: operator!=(const Circle& other) const
    {
        return !(*this == other);
    }
    
    ostream& operator<<(ostream& os, const Circle& circle)
    {
        os << "Center: (" << circle.x << ", " << circle.y << "), radius: " << circle.radius;
        return os;
    }

    istream& operator>>(istream& is, Circle& circle)
    {
        is >> circle.x >> circle.y >> circle.radius;
        if (circle.radius <= 0)
        {
            cout << "Ошибка: радиус должен быть положительным.\n";
            circle.radius = 1;
        }
        return is;
    }