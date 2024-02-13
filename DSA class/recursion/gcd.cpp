#include <iostream>
using namespace std;

int gcdRec(int a, int b)
{
    if (a > b)
    {
        return gcdRec(a - b, b);
    }
    else if (b > a)
    {
        return gcdRec(a, b - a);
    }
    else
    {
        return a;
    }
}

int main()
{
    int m, n;
    cout << "Enter two numbers to find their GCD(HCF): ";
    cin >> m >> n;

    cout << "The GCD(HCF) of " << m << " and " << n << " is: " << gcdRec(m, n);
}