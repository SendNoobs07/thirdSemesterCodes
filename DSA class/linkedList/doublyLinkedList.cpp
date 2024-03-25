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

    void insertAtFront(int x)
    {
        Node *newNode = new Node;

        if (head == NULL) // assuming that there is only one element
        {
            head = newNode;
            newNode->data = x;
        }
        else // when there is already an element
        {
            newNode->next = head; // while newNode's next holds value of current head
            head->previous = newNode;
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
            newNode->data = x;
        }
        else // when there is already an element
        {
            Node *newNode = new Node;
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            newNode->previous = temp; // connecting new node with previous node
            temp->next = newNode;     // connecting tail(temp) node with new node
            newNode->data = x;        // assigning value to newNode's data
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
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        cout << "NULL";
        while (temp != NULL)
        {
            cout << "<-" << temp->data;
            temp = temp->previous;
        }
        cout << endl;
    }

    void deleteFromFront()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            Node *temp = head;
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                head->previous = NULL;
            }

            delete temp;
        }
    }

    void deleteFromBack()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            Node *temp = tail;
            if (head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                tail = tail->previous;
                tail->next = NULL;
            }

            delete temp;
        }
    }

    void deleteFromBetween()
    {
        if (head == NULL)
        {
            cout << "Can't delete the list is empty." << endl;
        }
        else
        {
            int ind;
            cout << "Enter an index to delete from: ";
            cin >> ind;

            Node *temp;
            int i = 0;
            for (i = 0, temp = head; (i < ind - 1) && (temp->next->next != head); i++, temp = temp->next)
                ;
            Node *toDel = temp->next;
            if (temp->next->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = temp->next->next;
                temp->next->next->previous = temp;
            }

            delete toDel;
        }
    }

    void mainProcess()
    {
        int uInput;
        do
        {
            cout << "Choose an operation from below: " << endl;
            cout << "1 ) Insert at front" << endl
                 << "2 ) Insert at back" << endl
                 << "3 ) Insert in between" << endl
                 << "4 ) Traverse from front" << endl
                 << "5 ) Traverse from back" << endl
                 << "6 ) Delete from front" << endl
                 << "7 ) Delete from back" << endl
                 << "8 ) Delete from between" << endl
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
                int valueb, pos;
                cout << "Enter a number to input: ";
                cin >> valueb;
                cout << "Enter a position : ";
                cin >> pos;
                insertBetween(valueb, pos);
                break;

            case 4:
                traverseNext();
                break;

            case 5:
                traversePrevious();
                break;

            case 6:
                deleteFromFront();
                break;

            case 7:
                deleteFromBack();
                break;

            case 8:
                deleteFromBetween();
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
};

int main()
{
    DoublyLinkedList d1;
    d1.mainProcess();
}
