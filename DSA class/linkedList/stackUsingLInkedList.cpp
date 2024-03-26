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

class StackLinkedList
{
public:
    Node *top = NULL;

    void pushToStack(int x)
    {
        Node *newNode = new Node;

        if (top == NULL)
        {
            top = newNode;
            newNode->data = x;
        }

        else
        {
            newNode->next = top;
            top = newNode;
            newNode->data = x;
        }
    }

    void popFromStack()
    {
        if (top == NULL)
        {
            cout << "Void deletion" << endl;
        }
        else
        {
            cout << top->data << " was popped" << endl;
            top = top->next;
        }
    }

    void peekStackTop()
    {
        cout << top->data << " is on top of stack." << endl;
    }
};

int main()
{
    StackLinkedList q1;
    q1.pushToStack(6);
    q1.pushToStack(7);
    q1.pushToStack(8);
    q1.peekStackTop();
    q1.popFromStack();
    q1.peekStackTop();
    q1.pushToStack(9);
    q1.pushToStack(10);
    q1.peekStackTop();
    q1.popFromStack();
    q1.peekStackTop();
}