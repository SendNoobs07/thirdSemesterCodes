#include <iostream>
using namespace std;

int main()
{
    int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (demo[i] > demo[j])
            {
                int temp = demo[i];
                demo[i] = demo[j];
                demo[j] = temp;

                // cout << endl << demo[j] << " ->  <- " << demo[i] << endl;
                // for (int k = 0; k < 10; k++)
                // {
                //     cout << demo[k] << ", ";
                // }
            }
        }
    }

    cout << endl << "final answer: ";
    for (int k = 0; k < 10; k++)
    {
        cout << demo[k] << ", ";
    }
}