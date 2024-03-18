#include <iostream>
using namespace std;

class Test
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

    void mainProcess(){
        exchange(demo[1],demo[4]);

        for(int i=0;i<10;i++)
        {
            cout<<demo[i]<<", ";
        }
    }
};

int main()
{
    Test t1;
    t1.mainProcess();
    return 0;
}