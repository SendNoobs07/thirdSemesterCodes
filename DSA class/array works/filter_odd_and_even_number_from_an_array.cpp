#include <iostream>
using namespace std;

class Demo
{
public:
    int demoArray[10] = {6, 4, 5, 7, 8, 9, 1, 77, 33, 32};
    int even_count = 0, odd_count = 0;

    void even_odd_filter()
    {
        int eArr[10], oArr[10];

        // filtering process
        for (int i = 0; i < max; i++)
        {
            if (demoArray[i] % 2 == 0)
            {
                eArr[even_count] = demoArray[i];
                even_count++;
            }
            else
            {
                oArr[odd_count] = demoArray[i];
                odd_count++;
            }
        }

        // displaying process
        cout << "The even numbers are: ";
        for (int i = 0; i < even_count; i++)
        {
            cout << eArr[i] << "  ";
        }

        cout << "\nThe odd numbers are: ";
        for (int i = 0; i < odd_count; i++)
        {
            cout << oArr[i] << "  ";
        }
    }
};

int main()
{
    Demo demo;
    demo.even_odd_filter();
    return 0;
}
