#pragma once
#include <iostream>
#include <cmath>

using namespace std;

static double PI = 3.14;

class Circle
{
private:
	double x;
	double y;
	double radius;

public:
    Circle(double, double, double);

    Circle();

    ~Circle();

    Circle(const Circle& other);

    void print();

    double area() const;

    friend Circle operator+(const Circle& a, const Circle& b);

    friend Circle operator-(const Circle& a, const Circle& b);

    friend Circle operator*(const Circle& c, double n);

    friend Circle operator/(const Circle& c, double n);

    Circle operator~();

    Circle operator++();

    Circle operator--();

    Circle operator++(int);

    Circle operator--(int);

    bool operator<(const Circle& other);

    bool operator>(const Circle& other);

    bool operator<=(const Circle& other) const;

    bool operator>=(const Circle& other) const;

    Circle& operator=(const Circle& other);

    bool operator==(const Circle& other) const;

    bool operator!=(const Circle& other) const;

    friend ostream& operator<<(ostream& os, const Circle& circle);

    friend istream& operator>>(istream& is, Circle& circle);
};