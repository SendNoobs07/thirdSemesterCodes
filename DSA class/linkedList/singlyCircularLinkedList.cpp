#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int value)
    {
        this->data = value;
    }
};

class SinglyCircularLinkedList
{
    Node *head = NULL;
    Node *tail = NULL;

public:
    bool checkHead();
    void insertAtFront(int);
    void insertAtBack(int);
    void insertBetween(int, int);
    void traverse();
    void mainProcess();
};

bool SinglyCircularLinkedList::checkHead()
{
    return (head != NULL) ? 1 : 0;
}

void SinglyCircularLinkedList::insertAtFront(int value)
{
    Node *newNode = new Node(value);
    if (checkHead() == 0) // 0 means null
    {
        head = newNode;
        tail = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    cout << newNode->data << " has been inserted at front" << endl;
}

void SinglyCircularLinkedList::insertAtBack(int value)
{
    Node *newNode = new Node(value);
    if (checkHead() == 0) // 0 means null
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    cout << newNode->data << " has been inserted at back" << endl;
}

void SinglyCircularLinkedList::insertBetween(int value, int index)
{
    Node *newNode = new Node(value);
    if (checkHead() == 0) // 0 means null
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *temp = head;
        int i = 1;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << newNode->data << " has been inserted" << endl;
}

void SinglyCircularLinkedList::traverse()
{
    if (checkHead() == 0)
    {
        cout << "Can't traverse the list is empty." << endl;
        return;
    }
    else
    {
        cout << "The contents of the list are: " << endl;
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        }while (temp != head);
        cout << "NULL" << endl;
    }
}

void SinglyCircularLinkedList::mainProcess()
{
    int uInput;
    do
    {
        cout << "Choose an operation from below: " << endl;
        cout << "1 ) Insert at front" << endl
             << "2 ) Insert at back" << endl
             << "3 ) Insert in between" << endl
             << "4 ) Traverse" << endl
             << "5 ) Exit the program" << endl;
        cin >> uInput;
        switch (uInput)
        {
        case 1:
            int valuef;
            cout << "Enter a number to input: ";
            cin >> valuef;
            insertAtFront(valuef);
            break;

        case 2:
            int valuel;
            cout << "Enter a number to input: ";
            cin >> valuel;
            insertAtBack(valuel);
            break;

        case 3:
            int valueb, pos;
            cout << "Enter a number to input: ";
            cin >> valueb;
            cout << "Enter a position : ";
            cin >> pos;
            insertBetween(valueb, pos);
            break;

        case 4:
            traverse();
            break;

        case 5:
            cout << "Program is exiting..." << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }while(uInput!=5);
}

int main()
{
    SinglyCircularLinkedList s1;
    s1.mainProcess();
}
