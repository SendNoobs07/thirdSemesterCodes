#include <iostream>
#define ML 10
using namespace std;
class Circular
{
private:
    int front = -1, rear = -1;
    //           0   1  2  3 4 5 6 7 8  9
    int arr[ML];

public:
    void deque();
    void traverse();
    bool isEmpty();
    void enque(int x);
    bool isFull();
};

bool Circular::isFull()
{
    if ((rear + 1) % ML == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Circular::isEmpty()
{
    if (rear == -1 && front == -1 || rear == front) // default case
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Circular::deque()
{
    if (isEmpty())
    {
        cout << "Can't deque queue is already empty." << endl;
    }
    else if (front == rear)
    {
        cout << arr[front] << " will be dequed." << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << arr[front] << " will be dequed." << endl;
        front = (front + 1) % ML;
    }
}

void Circular::traverse()
{
    // Printing the array
    if (isEmpty())
    {
        cout << "Cannot traverse queue is emtpy." << endl;
    }
    else
    {
        cout << "The contents of Circular queue are: " << endl;
        for (int i = front; i != rear; i = (i + 1) % ML)
        {
            cout << arr[i] << "  ";
        }
        cout << arr[rear] << "  " << endl;
    }
}

void Circular::enque(int x)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        cout << x << " has been enqued." << endl;
        arr[rear] = x;
    }
    else
    {
        cout << x << " has been enqued." << endl;
        rear = (rear + 1) % ML;
        arr[rear] = x;
    }
}

int main()
{
    Circular c1;
    int opN;
    do
    {
        cout << "Choose an operation: " << endl;
        cout << "1 ) Enque" << endl
             << "2 ) Deque" << endl
             << "3 ) Traverse" << endl
             << "4 ) Exit" << endl;
        cin >> opN;

        switch (opN)
        {
        case 1:
            if (c1.isFull())
            {
                cout << "Cannot enque the queue is overflowed." << endl;
            }
            else
            {
                int uin;
                cout << "Enter a number to enque: ";
                cin >> uin;
                c1.enque(uin);
            }
            break;
        case 2:
            c1.deque();
            break;
        case 3:
            c1.traverse();
            break;
        case 4:
            cout << "Program is exiting...";
            break;
        default:
            cout << "Invalid input, try again!!..." << endl;
            break;
        }
    } while (opN != 4);
}
