#include <iostream>
using namespace std;

class Node
{
protected:
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

    Node(Node &n1) // to replace node we use copy constructor for easy use
    {
        this->parent = n1.parent;
        this->childL = n1.childL;
        this->childR = n1.childR;
        // we replace everything except the data
    }
};

class BinarySearchTree
{
protected:
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
        if ((temp->childL && temp->childR) == NULL) // assuming the node is leaf node
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

    // DONE CODE BELOW MYSELF
    // Node *insertPlaceFinder(Node *temp) // root goes to temp
    // {
    //     if (checkChildOfNode(temp) == 0) // assuming current node has no child
    //     {
    //         return temp;
    //     }
    //     else if (val <= temp->data) // assuming value is less than or equal to current node
    //     {
    //         if (temp->childL == NULL) // incase current child has no left child
    //         {
    //             return temp;
    //         }
    //         temp = temp->childL;
    //         temp = insert(temp);
    //     }
    //     else // assuming value is greater than current node
    //     {
    //         if (temp->childR == NULL) // incase current child has no right child
    //         {
    //             return temp;
    //         }
    //         temp = temp->childR;
    //         temp = insert(temp);
    //     }
    //     return temp;
    // }

    Node *insertPlaceFinder(Node *temp) // root goes to temp
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else if (val <= temp->data)
        {
            if (temp->childL == NULL)
            {
                return temp;
            }
            temp = insertPlaceFinder(temp->childL);
        }
        else
        {
            if (temp->childR == NULL)
            {
                return temp;
            }
            temp = insertPlaceFinder(temp->childR);
        }

        return temp;
    }

    Node *deletePlaceFinder(Node *temp) // root goes to temp
    {
        if (temp == NULL)
        {
            return NULL;
        }
        else if (temp == val)
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

    Node *delFromLeftNodeFinder(Node *temp) // to find greatest child to replace from left
    {
        if (temp->childR == NULL)
        {
            return temp;
        }
        else
        {
            temp = delFromLeftNodeFinder(temp->childR);
            return temp;
        }
    }

    void insert()
    {
        cout << "Enter value to insert: ";
        cin >> val;
        curr = insertPlaceFinder(root); // returns temp that points to the desired location

        Node *newNode = new Node;

        if (val <= curr->data)
        {
            curr->childL = newNode;
        }
        else
        {
            curr->childR = newNode;
        }
        newNode->parent = curr;
        newNode->data = val;
    }

    void delete()
    {
        cout << "Enter value to delete: ";
        cin >> val;
        curr = deletePlaceFinder(root);

        if (curr == NULL)
        {
            cout << "Could not find the given element." << endl;
        }
        else // assuming we replace deleted element with left child
        {
            Node *temp = new Node;
            temp = curr;
            temp = temp->childL; // selecting the left child of the node to delete
            temp = delFromLeftNodeFinder(temp);

            curr->data = temp->data;

            delete temp;
        }
    }
};
