#include <iostream>
#include <cmath>

#include "complex.h"

using namespace std;

void test_complex()
{
    Complex c1(1.0, 2.0, false);
    cout<<"c1 = ";
    c1.display(cout);
    Complex c2(3.0, M_PI, true);
    cout<<"c2 = ";
    c2.display(cout);
    Complex c3;
    cout<<"c3 = ";
    c3.display(cout);

    Complex produit = c1 * c2;
    cout<<"c1 * c2 = ";
    produit.display(cout);
    try
    {
        Complex div = c2 / c3;
        div.display(cout);
    }
    catch(runtime_error e)
    {
        cout<<e.what()<<endl;
    }
    if(c2 == c3)
        cout<<"c2 = c3"<<endl;
    else
        cout<<"c2 != c3"<<endl;

}

int main()
{
    test_complex();
    return 0;
}
