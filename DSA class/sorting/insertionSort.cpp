#include <iostream>
using namespace std;

class InsertionSort
{
private:
    int demo[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

public:
    void exchange(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void sortLeft(int &x, int &y, int i)
    {
        if ((i != 0) && x > y)
        {
            cout << x << " and " << y << " were exchanged." << endl;
            exchange(x, y);
            cout << demo[i - 2] << " and " << demo[i-1] << " were sent for further sort." << endl;
            //(IGNORE IF SOME RANDOM VALUE COMES WITH LEASE VALUE AS IT IS IN FRONT OF ARRAY AND IT DISPLAYS SOMETHING FROM INDEX i-1)
            sortLeft(demo[i - 2], demo[i-1], i - 1);
        }
        else
        {
            cout << "-------------------- SORTING HALTED --------------------" << endl;
            return;
        }
    }

    void mainProcess()
    {
        for (int i = 1; i <= 10; i++)
        {
            cout << "ITERATION " << i << endl;
            if (demo[i - 1] > demo[i])
            {
                cout << "Needs to be exchanged" << endl;
                cout << demo[i - 1] << " and " << demo[i] << " were sent to sort." << endl;
                sortLeft(demo[i - 1], demo[i], i);
            }
            else{
                cout<<"Iteration increased......"<<endl<<endl;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            cout << demo[i] << ", ";
        }
    }
};

int main()
{
    InsertionSort i1;
    i1.mainProcess();
    return 0;
}
