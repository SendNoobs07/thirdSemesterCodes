#include <iostream>
using namespace std;

int main()
{
    //             0    1   2   3  4  5  6  7  8   9
    int Arr[10] = {11, 12, 13, 14, 5, 6, 7, 8, 9, 10};
    int front = 8, rear = 7;

    if ((front == (rear + 1) % 10) || (rear == (front - 1) % 10))
    {
        cout << "Queue is overflow." << endl;
    }
    else
    {
        rear = (rear + 1) % 10;
        cout << "THIS WORKS!!, New value of rear is: " << rear;
    }
}