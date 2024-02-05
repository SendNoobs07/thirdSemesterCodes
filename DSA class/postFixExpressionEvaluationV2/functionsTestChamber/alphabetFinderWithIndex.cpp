#include <iostream>
using namespace std;
bool isAlphabet(char x)
{
    switch (x)
    {
    case 'A' ... 'Z':
    case 'a' ... 'z':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

int main()
{
    int alphabetFlagIndex[11], numOfAlphabets = 0;
    int exampleInt[11];
    char exampleAlphabets[11] = {'a', 'b', 'c', '$', '$', 'd', 'e', '+', '*', 'f', '/'};
    for (int i = 0; i < 11; i++)
    {
        if (isAlphabet(exampleAlphabets[i]) == 1)
        {
            cout << "Enter value of " << exampleAlphabets[i] << " : ";
            cin >> exampleInt[numOfAlphabets];
            alphabetFlagIndex[numOfAlphabets] = i;
            numOfAlphabets++;
        }
    }
    cout << "Example Array with Alphabets : " << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << exampleAlphabets[i] << "  ";
    }

    cout << endl
         << "Example Array with numbers : " << endl;
    for (int i = 0; i < numOfAlphabets; i++)
    {
        cout << exampleInt[i] << "  ";
    }

    cout << endl
         << "Collection of Index with alphabets : " << endl;
    for (int i = 0; i < numOfAlphabets; i++)
    {
        cout << alphabetFlagIndex[i] << "  ";
    }
}