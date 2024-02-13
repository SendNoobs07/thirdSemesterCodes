#include<iostream>
using namespace std;

int factRec(int n){
    if(n==0)
    {
        return 1;
    }
    return n*factRec(n-1);
}

int main()
{
    int n;
    cout<<"Enter a number to find it's factorial: ";
    cin>>n;

    cout<<"The factorial of "<<n<<" is: "<<factRec(n);
}