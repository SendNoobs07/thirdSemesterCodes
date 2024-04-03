#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *parent = NULL;
    Node *childL = NULL;
    Node *childR = NULL;

public:
    Node()
    {
        this->parent = NULL;
        this->childL = NULL;
        this->childR = NULL;
        this->data = 0;
    }
};

class BinarySearchTree
{
public:
    Node *root = NULL;
    Node *curr = NULL;
    int val;

public:
    BinarySearchTree()
    {
        this->root = NULL;
    }

    int checkChildOfNode(Node *temp) // to check the status of the node
    {
        if ((temp->childL == NULL) && (temp->childR == NULL)) // assuming the node is leaf node
        {
            return 0;
        }
        else if ((temp->childL != NULL) && (temp->childR != NULL)) // assuming the node has both left and right child
        {
            return 2;
        }
        else // assuming the node has atleast one child
        {
            return 1;
        }
    }

    Node *insertNodeFinder(Node *temp) // root goes to temp
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else if (val <= temp->data)
        {
            if (temp->childL == NULL)
            {
                cout << "ON THE LEFT, Below " << temp->data << endl;
                return temp;
            }
            temp = insertNodeFinder(temp->childL);
        }
        else
        {
            if (temp->childR == NULL)
            {
                cout << "ON THE RIGHT, Below " << temp->data << endl;
                return temp;
            }
            temp = insertNodeFinder(temp->childR);
        }
        return temp;
    }

    Node *deletePlaceFinder(Node *temp) // root goes to temp
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else if (temp->data == val)
        {
            return temp;
        }
        else
        {
            Node *result;
            result = deletePlaceFinder(temp->childL);
            if (result != NULL)
            {
                return result;
            }
            result = deletePlaceFinder(temp->childR);
            return result;
        }
    }

    Node *leftReplacementNodeFinderForDel(Node *temp) // to find greatest child to replace from left
    {
        if (temp->childR == NULL)
        {
            return temp;
        }
        else
        {
            temp = leftReplacementNodeFinderForDel(temp->childR);
            return temp;
        }
    }

    void insert(int x)
    {
        // cout << "Enter value to insert: ";
        // cin >> val;

        val = x;
        curr = insertNodeFinder(root); // returns temp that points to the desired location

        Node *newNode = new Node;

        if (curr == NULL)
        {
            newNode->data = val;
            root = newNode;
            return;
        }
        else if (val <= curr->data)
        {
            curr->childL = newNode;
        }
        else
        {
            curr->childR = newNode;
        }
        newNode->parent = curr;
        newNode->data = val;
        cout << "Val is : " << newNode->data << endl;
    }

    void deleteFromTree(int val)
    {
        // cout << "Enter value to delete: ";
        // cin >> val;
        this->val = val;
        curr = deletePlaceFinder(root);

        if (curr == NULL)
        {
            cout << "Could not find the given element." << endl;
        }
        else // assuming we replace deleted element with left child
        {
            Node *temp = curr->childL; // selecting the left child of the node to delete
            temp = leftReplacementNodeFinderForDel(temp);

            curr->data = temp->data;
            temp->parent->childR = NULL;
            delete temp;
        }
    }

    void preTraverse(Node *temp)
    {
        if (temp == NULL)
        {
            cout << "Can't traverse the tree is empty." << endl;
            return;
        }
        else
        {
            cout << "Current Node: " << temp->data << endl;
            if (temp->childL != NULL)
            {
                preTraverse(temp->childL);
            }
            if (temp->childR != NULL)
            {
                preTraverse(temp->childR);
            }
            return;
        }
    }

    void mainProcess()
    {
        insert(20);
        insert(5);
        insert(17);
        insert(8);
        insert(50);
        insert(23);
        insert(62);
        insert(25);
        insert(33);
        insert(9);
        insert(81);

        preTraverse(root);

        deleteFromTree(50);
        preTraverse(root);
    }
};

int main()
{
    BinarySearchTree b1;
    b1.mainProcess();
}
