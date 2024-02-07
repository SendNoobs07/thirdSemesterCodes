/*
TO DO's:
Enque
Deque
Make empty
Check if queue is full
Check if queue is empty
Traverse through queue
*/

#include <iostream>
#define MAX_LENGTH 10
using namespace std;

class Queue
{
private:
    int front = 0, rear = -1, queue[MAX_LENGTH];

public:
    bool isFull()
    {
        if (rear == MAX_LENGTH - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isEmpty()
    {
        if (rear < front)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void makeEmpty()
    {
        rear = -1;
        front = 0;
        cout<<"Queue is now empty."<<endl;
    }

    void enque()
    {
        if (isFull() == 1)
        {
            cout << "Can't enque queue is already full." << endl;
        }
        else
        {
            int uInput;
            cout << "Enter a number to enque: ";
            cin >> uInput;
            rear++;
            queue[rear] = uInput;
        }
    }

    void deque()
    {
        if (isEmpty() == 1)
        {
            cout << "Can't deque queue is empty." << endl;
        }
        else
        {
            cout << queue[front] << " has been dequed." << endl;
            front++;
        }
    }

    void traverse()
    {
        if (isEmpty() == 1)
        {
            cout << "Can't traverse queue is empty." << endl;
        }
        else
        {
            cout << "The contents of queue are: " << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << "  ";
            }
            cout << endl;
        }
    }

    void mainProcess()
    {
        int operationNumber;
        do
        {
            cout << "Enter an operation from below: " << endl;
            cout << "1 ) Enque" << endl;
            cout << "2 ) Deque" << endl;
            cout << "3 ) Make queue empty" << endl;
            cout << "4 ) Check if queue is full" << endl;
            cout << "5 ) Check if queue is empty" << endl;
            cout << "6 ) Traverse through queue" << endl;
            cout << "7 ) Exit" << endl;
            cin >> operationNumber;

            switch (operationNumber)
            {
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                makeEmpty();
                break;
            case 4:
                if (isFull() == 1)
                {
                    cout << "The queue is Full." << endl;
                }
                else
                {
                    cout << "The queue is not Full." << endl;
                }
                break;
            case 5:
                if (isEmpty() == 1)
                {
                    cout << "The queue is Empty." << endl;
                }
                else
                {
                    cout << "The queue is not Empty." << endl;
                }
                break;
            case 6:
                traverse();
                break;
            case 7:
                cout << "Program is Exiting..." << endl;
                break;
            default:
                cout << "Invalid input please try again..." << endl;
                break;
            }
        } while (operationNumber != 7);
    }
};
int main()
{
    Queue q1;
    q1.mainProcess();
}
