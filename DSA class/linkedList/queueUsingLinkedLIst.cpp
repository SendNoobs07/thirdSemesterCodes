#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class QueueLinkedList
{
public:
    Node *front = NULL;
    Node *rear = NULL;

    void enqueue(int x)
    {
        Node *newNode = new Node;

        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            newNode->data = x;
        }

        else
        {
            Node *temp = front;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            rear = newNode;
            newNode->data = x;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Void deletion" << endl;
        }
        else if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            cout << front->data << " was dequeued" << endl;
            front = front->next;
        }
    }

    void traverseThroughQueue()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data
                 << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    QueueLinkedList q1;
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.traverseThroughQueue();
    q1.dequeue();
    q1.traverseThroughQueue();
    q1.enqueue(9);
    q1.enqueue(10);
    q1.traverseThroughQueue();
    q1.dequeue();
    q1.traverseThroughQueue();
    // q1.mainProcess();
}