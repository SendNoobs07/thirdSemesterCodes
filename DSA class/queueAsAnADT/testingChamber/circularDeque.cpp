#include <iostream>
using namespace std;

int main()
{
    //             0    1   2   3  4  5  6  7  8   9
    int Arr[10] = {11, 12, 13, 14, 5, 6, 7, 8, 9, 10};
    int front = 0, rear = 0;

    

//     if ((rear == -1) && (front == 0)) // default case
//     {
//         cout << "Can't deque the queue is empty." << endl;
//     }
//     else if(front==rear)
//     {
//         cout << "Dequed value is: " << Arr[front] << endl;
//         front = (front + 1) % 10;
//     }
//     else if (front>rear)
//     {
//         cout << "THIS WORKS!!, Dequed value is: " << Arr[front] << endl;
//         front = (front + 1) % 10;
//     }
//     else if (front + 1 == rear)
//     {
//         cout << "THIS WORKS!!, Dequed value is: " << Arr[front] << endl;
//         front = (front + 1) % 10;
//     }
// }