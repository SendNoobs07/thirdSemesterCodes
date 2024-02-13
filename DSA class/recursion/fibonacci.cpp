#include<iostream>
using namespace std;

int fiboRec(int n){
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    return fiboRec(n-1)+fiboRec(n-2);
}

int main()
{
    int n;
    cout<<"Enter a number to find it's nth position from fibonacci series: ";
    cin>>n;

    cout<<"The "<<n<<"th term in fibonacci series is: "<<fiboRec(n);
}