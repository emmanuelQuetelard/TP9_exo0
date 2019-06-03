#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdexcept>

using namespace std;

class Complex
{
private:
    double my_a;
    double my_b;
    double my_ro;
    double my_theta;

public:
    Complex(const double& a = 0, const double& b = 0, const bool& polaire = false);
    Complex operator+(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const throw(runtime_error);
    Complex operator-(const Complex& c) const;
    bool operator==(const Complex& c) const;
    void display(ostream& os) const throw();

};

#endif // COMPLEX_H
