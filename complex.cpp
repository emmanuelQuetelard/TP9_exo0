#include "complex.h"

#include <cmath>
#include <ostream>

Complex::Complex(const double& a, const double& b, const bool& polaire)
{
    if(polaire)
    {
        my_ro = a;
        my_theta = b;
        my_a = my_ro * cos (my_theta);
        my_b = my_ro * sin (my_theta);
    }
    else {
       my_a = a;
       my_b = b;
       my_ro = sqrt(a * a + b * b);
       if(a >= 0)
           my_theta = asin(b / my_ro);
       else {
           my_theta = M_PI - asin(b / my_ro);
       }
    }
}

Complex Complex::operator+(const Complex& c) const
{
    return Complex(my_a + c.my_a, my_b + c.my_b);
}

Complex Complex::operator*(const Complex& c) const
{
    return Complex(my_a * c.my_a - my_b * c.my_b, my_b * c.my_a + c.my_b * my_a);
}

Complex Complex::operator/(const Complex& c) const throw(runtime_error)
{
    double denom = c.my_a * c.my_a - c.my_b * c.my_b + 2 * c.my_a * c.my_b;
    if(denom == 0)
        throw runtime_error("erreur : division par zéro");
    return Complex((my_a * c.my_a - my_b * c.my_b) / denom, (my_a * c.my_b + c.my_a * my_b) / denom);
}

Complex Complex::operator-(const Complex& c) const
{
    return Complex(my_a - c.my_a, my_b - c.my_b);
}

bool Complex::operator==(const Complex& c) const
{
    return (my_a == c.my_a && my_b == c.my_b);
}

void Complex::display(ostream& os) const throw()
{
    os<<my_a<<" + i * "<<my_b<<endl;
}
