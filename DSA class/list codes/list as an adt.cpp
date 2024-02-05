
#include <iostream>
#define MAX_LENGTH 10
using namespace std;

class List
{
private:
    int list[MAX_LENGTH], top;

public:
    List()
    {
        top = -1;
    }

    void makeEmptyList()
    {
        if (checkEmpty() == 1)
        {
            cout << "List is already empty." << endl;
        }
        else
        {
            top = -1;
            cout << "List's contents has been deleted." << endl;
        }
    }

    bool checkEmpty()
    {
        if (top < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool checkFull()
    {
        if (top == MAX_LENGTH - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void insert()
    {
        if (checkFull() == 1)
        {
            cout << "CAN'T INSERT THE LIST IS ALREADY FULL" << endl;
        }
        else
        {
        	top++;
        	int pos=1;
        	if(top-1!=-1){
        		cout<<"Enter position to insert in: ";
        		cin>>pos;
			}
			int userInput;
			cout<<"Enter the number to insert: ";
			cin>>userInput;
			if(pos<=top){
				int t=top;
				for(t;t>=pos;t--)
				{
					list[t]=list[t-1];
				}
				list[pos-1]=userInput;
			}
			else{
				list[top]=userInput;
			}
		}
    }

    void deleteFromList()
    {
        if (checkEmpty() == 1)
        {
            cout << "CAN''T DELETE THE LIST IS EMPTY" << endl;
        }
        else
        {
        	int dPos=1;
        	cout<<"Enter position to delete in: ";
        	cin>>dPos;
        	for(int p=dPos;p<=top;p++)
        	{
        		list[p-1]=list[p];
			}
        	top--;
		}
		
    }

    void traverse()
    {
        if (checkEmpty() == 1)
        {
            cout << "THE LIST IS EMPTY CANNOT TRAVERSE" << endl;
        }
        else
        {
            cout << "The contents of list are: " << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << "  " << list[i] << "  ";
            }
            cout << endl;
        }
    }

    void peek()
    {
        if (checkEmpty() == 1)
        {
            cout << "CAN'T PEEK THE LIST IS EMPTY" << endl;
        }
        else
        {
            cout << "The element on top is: " << list[top] << endl;
        }
    }

    void mainProcess()
    {
        int operationNumber = 0;
        do
        {
            cout << "Enter a number representing operations from below: " << endl;
            cout << "1 ) Insert" << endl;
            cout << "2 ) Delete" << endl;
            cout << "3 ) Check if list is full" << endl;
            cout << "4 ) Check if list is empty" << endl;
            cout << "5 ) Make list empty" << endl;
            cout << "6 ) Traverse" << endl;
            cout << "7 ) Peek top" << endl;
            cout << "8 ) Exit program" << endl;
            cin >> operationNumber;

            switch (operationNumber)
            {
            case 1:
                insert();
                break;
            case 2:
                deleteFromList();
                break;
            case 3:
                if (checkFull() == 1)
                {
                    cout << "The list is full." << endl;
                }
                else
                {
                    cout << "The list is not full." << endl;
                }
                break;
            case 4:
                if (checkEmpty() == 1)
                {
                    cout << "The list is empty." << endl;
                }
                else
                {
                    cout << "The list is not empty." << endl;
                }
                break;
            case 5:
                makeEmptyList();
                break;
            case 6:
                traverse();
                break;
            case 7:
                peek();
                break;
            case 8:
                cout << "Program is exiting...";
                break;
            default:
                cout << "Invalid input, insert again!!" << endl;
            }
        } while (operationNumber != 8);
    }
};

int main()
{
    List l1;
    l1.mainProcess();
}