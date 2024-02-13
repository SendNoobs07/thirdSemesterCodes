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

class SinglyLinkedList
{
public:
    Node *head = NULL;

    void insertAtFront(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->data = x;
        }

        else
        {
            newNode->data = x;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtBack(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            newNode->data = x;
        }

        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->data = x;
        }
    }

    void insertBetween(int x, int ind)
    {
        Node *newNode = new Node;

        Node *temp = head;
        int i = 0;

        while (i < ind - 1)
        {
            cout << "i : " << i << ", temp points to : " << temp->data << endl;
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->data = x;
    }

    void deleteFromList(int x)
    {
        Node *temp = head;

        if (temp->data == x) // incase if the element is at first the while loop below won't work
        {
            head = temp->next;
            return;
        }
        else
        {
            while (temp->next->data != x)
            {
                temp = temp->next;
            }
            temp->next=temp->next->next;
        }
    }

    bool search(int x)
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "Can't search the list is empty." << endl;
            return 0;
        }

        int flag = 0;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            cout << x << " was found." << endl;
            return 1;
        }
        else
        {
            cout << x << " was not found." << endl;
            return 0;
        }
    }

    void traverse()
    {
        Node *temp = head;

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
    SinglyLinkedList l1;
    l1.insertAtFront(5);
    l1.insertAtFront(6);
    l1.insertAtFront(7);
    l1.insertAtFront(8);
    l1.insertAtBack(69);
    l1.insertAtBack(29);
    l1.insertBetween(55, 6);
    l1.traverse();
    l1.search(69);
    l1.search(68);
    l1.search(7);
    l1.deleteFromList(69);
    l1.traverse();
    l1.deleteFromList(8);
    l1.traverse();
    l1.deleteFromList(5);
    l1.traverse();
    l1.deleteFromList(6);
    l1.traverse();
}