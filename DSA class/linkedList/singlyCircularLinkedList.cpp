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
    void traverseFromBetween(int index);
    void mainProcess();
    void deleteFromList(int index);
    void deleteFromFront();
    void deleteFromBack();
};

bool SinglyCircularLinkedList::checkHead()
{
    return (head != NULL) ? 1 : 0;
}

void SinglyCircularLinkedList::deleteFromList(int index)
{
    Node *temp = head;
    if (index == 0) // if user gives front index
    {
        if (tail == head) // incase there is only one element in list
        {
            tail = NULL;
            head = NULL;
            delete temp;
        }
        else // if there is more than one
        {
            head = head->next;
            delete temp;
        }
    }
    else
    {
        int i = 1;
        while (i < index) // traversing through the list
        {
            temp = temp->next;
            i++;
        }

        Node *deletedNode = temp->next; // creating a new pointer to point towards the deleted node
        if (deletedNode->next == NULL)  // incase if the user gives index which is the final node of list
        {
            tail = temp;       // updating tail to temp which is at 2nd last of the list
            temp->next = NULL; // updating next of 2nd last element to null
        }
        else
        {
            temp->next = temp->next->next; // else refers to when the element is in between
        }
        cout << deletedNode->data << " was deleted" << endl;
        delete deletedNode;
    }
}

void SinglyCircularLinkedList::deleteFromFront()
{
    if (head == NULL)
    {
        cout << "Void deletion" << endl;
    }
    else
    {
        Node *deletedNode = head;
        if (head->next == NULL) // incase there is only one element
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next; // updating head to second element
            tail->next = head; // updating next of last element to new head
        }
        cout << deletedNode->data << " was deleted" << endl;
        delete deletedNode;
    }
}

void SinglyCircularLinkedList::deleteFromBack()
{
    if (head == NULL) // incase the list is empty
    {
        cout << "Void deletion" << endl;
    }
    else
    {
        Node *temp = head;
        Node *deletedNode = temp;

        if (head->next == NULL) // incase there is only one element in the list
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            while (temp->next->next != NULL) // traversing through the list
            {
                temp = temp->next;
            }
            deletedNode = temp->next;
            temp->next = NULL;
            tail = temp;
        }
        cout << deletedNode->data << " was deleted" << endl;
        delete deletedNode;
    }
}

void SinglyCircularLinkedList::insertAtFront(int value)
{
    Node *newNode = new Node(value);
    if (checkHead() == 0) // 0 means null
    {
        head = newNode;
        tail = head;
        newNode->next = newNode;
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
        while (i < index && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        if (i != index)
        {
            cout << "Invalid position." << endl;
            delete newNode; // Free memory if insertion fails
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    cout << newNode->data << " has been inserted at position " << index << endl;
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
        } while (temp != head);
        cout << "NULL" << endl;
    }
}

void SinglyCircularLinkedList::traverseFromBetween(int index) // this function is to check the circular property
{
    if (checkHead() == 0) // incase the list is empty
    {
        cout << "Can't traverse the list is empty." << endl;
        return;
    }
    else
    {
        cout << "The contents of the list from index " << index << " are: " << endl;
        Node *temp = head;
        int i = 1;
        while (i <= index) // traversing till we reach desired index
        {
            temp = temp->next;
            i++;
        }
        Node *indPoint = temp; // storing temp which points to desired index for stopping the loop
        do                     // traversing from the index to
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != indPoint);
        cout << "Finish" << endl;
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
             << "5 ) Traverse from between" << endl
             << "6 ) Delete from front" << endl
             << "7 ) Delete from back" << endl
             << "8 ) Delete in between" << endl
             << "9 ) Exit the program" << endl;
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
            int valueb, pos1;
            cout << "Enter a number to input: ";
            cin >> valueb;
            cout << "Enter a position : ";
            cin >> pos1;
            insertBetween(valueb, pos1);
            break;

        case 4:
            traverse();
            break;

        case 5:
            int pos2;
            cout << "Enter a position : ";
            cin >> pos2;
            traverseFromBetween(pos2);
            break;

        case 6:
            deleteFromFront();
            break;

        case 7:
            deleteFromBack();
            break;

        case 8:
            int ui;
            cout << "Enter an index to delete: ";
            cin >> ui;
            deleteFromList(ui);
            break;

        case 9:
            cout << "Program is exiting..." << endl;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    } while (uInput != 9);
}

int main()
{
    SinglyCircularLinkedList s1;
    s1.mainProcess();
}
