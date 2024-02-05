#include <iostream>
using namespace std;

int main()
{
    //             0    1   2   3  4  5  6  7  8   9
    int Arr[10] = {11, 12, 13, 14, 5, 6, 7, 8, 9, 10};
    int front = 7, rear = 0;
    if ((rear == -1) && (front == 0)) // default case
    {
        cout << "Can't traverse the queue is empty." << endl;
    }

    else if (front == rear)
    {
        cout << Arr[front] << "  "; // some conditions below conflicts when front==rear
    }

    else // other cases
    {
        if (front < rear) // when rear hasn't rotated
        {
            for (int i = front; i != rear + 1; i++)
            {
                cout << Arr[i] << "  ";
            }
        }

        else if (front > rear) // when rear has rotated
        {
            for (int i = front; i != (front - 1) % 10 && i != rear; i = (i + 1) % 10)
            {
                cout << Arr[i] << "  ";
            }
            cout << Arr[rear] << endl; // printing the final element that was left
        }
    }
}