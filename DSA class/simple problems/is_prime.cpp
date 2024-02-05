#include <iostream>
using namespace std;

    class Example
{
public:
    int userInput;
    int flag;
    void is_prime()
    {
        cout << "Enter a number: ";
        cin >> userInput;

        for (int i = 2; i < userInput; i++)
        {
            if (userInput % i == 0)
            {
                flag = 1;
                break;
            }
            else
            {
                continue;
            }
        }
    }
};

int main()
{
    Example E1;
    E1.is_prime();
    if(E1.flag==1){
        cout<<"The number is not a prime number."<<endl;
    }
    else{
        cout<<"The number is prime."<<endl;
    }
}