#include <iostream>
#define MAX_LENGTH 10
using namespace std;

class Queue
{
private:
    int front = 0, rear = -1, queue[MAX_LENGTH];
    int nOE = 0; // TO KEEP TRACK OF NUMBER OF ELEMENTS

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
        cout << "Queue is now empty." << endl;
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
            if (uInput >= queue[front]) // IF USER GIVES NUMBER THAT IS GREATER OR EQUAL THAN FRONT ELEMENT
            {
                rear++;
                for (int i = rear; i > front; i--)
                {
                    queue[i] = queue[i - 1];
                }
                queue[front] = uInput;
                cout << uInput << " will be enqued." << endl;
                nOE++;
            }
            else if (uInput <= queue[rear]) // IF USER'S INPUT IS LESS THAN REAR ELEMENT
            {
                rear++;
                queue[rear] = uInput;
                cout << uInput << " will be enqued." << endl;
                nOE++;
            }
            else // IF USER GIVES AN INPUT THAT IS TO BE KEPT IN BETWEEN DUE TO PRIORITY
            {
                rear++;
                for (int i = front + 1; i < nOE; i++) // LOOP TO TRAVERSE THROUGH THE ELEMENTS IN BETWEEN
                {
                    if (uInput >= queue[i])
                    {
                        for (int j = rear; j >= i; j--)
                        {
                            queue[j] = queue[j - 1];
                        }
                        queue[i] = uInput;
                        break;
                    }
                }
                cout << uInput << " will be enqued." << endl;
                nOE++;
            }
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
            nOE--;
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
            cout << "4 ) Traverse through queue" << endl;
            cout << "5 ) Exit" << endl;
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
                nOE = 0;//RESETS COUNTER OF NUMBER OF ELEMENTS
                break;
            case 4:
                traverse();
                break;
            case 5:
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
