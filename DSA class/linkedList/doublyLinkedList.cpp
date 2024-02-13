#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void insertAtFront(int x)
    {
        Node *newNode = new Node;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->data = x;
        }
        else // when there is already an element
        {
            head->previous = newNode; // previous of head holds the address of newNode
            newNode->next = head;     // while newNode's next holds value of current head

            head = newNode; // changing the head as new element is inserted at head(front)

            newNode->data = x; // putting value in new node could've also used
            // head->data=x as head has been updated and points towards newNode
        }
    }

    void insertAtBack(int x)
    {
        Node *newNode = new Node;

        if (head == NULL) // first time insertion case
        {
            head = newNode;
            tail = newNode;
            newNode->data = x;
        }
        else // when there is already an element
        {
            Node *newNode = new Node;

            newNode->previous = tail; // connecting new node with previous node
            tail->next = newNode;     // connecting tail node with new node

            newNode->data = x;// assigning value to newNode's data

            tail = newNode; // finally pointing tail to newNode
        }
    }

    void insertBetween(int x, int ind)
    {
        Node *newNode = new Node;
        int i = 0;

        Node *temp = head;
        while (i < ind - 1)
        {
            temp = temp->next;
            i++;
        }
        // CONNECTING NEXT POINTERS
        newNode->next = temp->next; // putting next address of left side of selected index to newNode
        temp->next = newNode;       // putting address of new node to next address of left side of selected index

        // CONNECTING PREVIOUS POINTERS
        newNode->previous = temp;
        newNode->next->previous = newNode;

        newNode->data = x; // putting value of x in newNode's data
    }

    void traverseNext()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void traversePrevious()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->data << "<-";
            temp = temp->previous;
        }
        cout << "NULL";
    }

    void mainProcess()
    {
        insertAtFront(9);
        insertAtBack(8);
        insertAtBack(6);
        insertAtBack(5);
        insertAtBack(4);

        cout<<endl<<"Before inserting in between: "<<endl<<"Next: ";
        traverseNext();
        cout<<endl<<"Previous: ";
        traversePrevious();

        insertBetween(7, 2);

        cout<<endl<<"After inserting in between: "<<endl<<"Next: ";
        traverseNext();
        cout<<endl<<"Previous: ";
        traversePrevious();
    }
};

int main()
{
    DoublyLinkedList d1;
    d1.mainProcess();
}