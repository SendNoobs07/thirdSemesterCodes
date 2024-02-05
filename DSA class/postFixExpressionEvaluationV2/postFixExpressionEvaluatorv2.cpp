#include <iostream>
#include <cmath> //for calculating power
#define MAX_LENGTH 30
using namespace std;

class PostEvaluator
{
private:
    char op;                     // BASIC VARIABLE for storing operator
    int op1, op2, stackTop = -1; // BASIC VARIABLES
    int alphabetIndexArray[20];  // THIS ARRAY STORES THE INDEX VALUES WHERE ALPHABETS ARE FOUND LENGTH COULD BE ANYTHING
    int postInt[MAX_LENGTH];     // THIS ARRAY STORES THE CHARACTER WITH THEIR RESPECTED VALUES ALONG WITH OPERATORS
    int numOfAlphabets = 0;      // THIS KEEPS TRACK OF NUMBER OF ALPHABETS FOUND IN EXPRESSION
    int stack[5];                // array length is the length of continuous variables before an operator in
                                 // post fix expression given by user
    int alphaIndex = 0;
    char postfixExpression[MAX_LENGTH];

public:
    // CONSTRUCTORS FOR TAKING EXPRESSION
    PostEvaluator()
    {
        cout << "Enter a post-fixed expression : ";
        cin >> postfixExpression;
    }

    bool isOperator(char x) // to check if scanCh is an operator or not
    {
        switch (x)
        {
        case '$':
        case '/':
        case '*':
        case '+':
        case '-':
            return 1;
            break;
        default:
            return 0;
        }
    }

    bool isStackFull() // checks if stack is full will be needed if any case happens when elements are more than 5
    {
        if (stackTop == 5 - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void traverse_stack() // displays contents of stack will be needed when displaying in a table or final answer
    {
        for (int i = 0; i <= stackTop; i++)
        {
            if (i == stackTop) // to prevent extra comma after final element in array
            {
                cout << stack[i];
            }
            else
            {
                cout << stack[i] << ", ";
            }
            // cout<<endl<<"Does this work?"<< i<<endl;
        }
    }

    void pushToStack(int x) // pushes it's parameter to stack
    {
        stackTop++;
        stack[stackTop] = x;
    }

    bool isAlphabet(char x)
    {
        switch (x)
        {
        case 'A' ... 'Z':
        case 'a' ... 'z':
            return 1;
            break;

        default:
            return 0;
            break;
        }
    }

    int operatorOperation(int x, char operation, int y) // TAKES PARAMETER AS operatorOperation(10,'/',2)
    // i.e. 10 divide by 2
    {
        switch (operation)
        {
        case '$':
            return pow(x, y);
            break;
        case '/':
            return x / y;
            break;
        case '*':
            return x * y;
            break;
        case '+':
            return x + y;
            break;
        case '-':
            return x - y;
            break;

        default:
            cout << "ERRORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR!!" << endl;
            return 0;
            break;
        }
    }

    void popFromStack()
    {
        stackTop--;
    }

    void mainProcess()
    {
        char scanCh;

        for (int i = 0; i < MAX_LENGTH && postfixExpression[i] != '\0'; i++) // CONVERTING VARIABLES OF POSTFIX EXPRESSION TO INTEGER WHILE TAKING THEIR
        // VALUES SIMULTANEOUSLY
        {
            if (isAlphabet(postfixExpression[i]) == 1) // RETURNS 1 OF EXPRESSION IS AN ALPHABET
            {
                cout << "Enter value of " << postfixExpression[i] << " : ";
                cin >> postInt[numOfAlphabets]; // STORING THE VALUES OF ALPHABETS IN ARRAY WITH POSTFIX EXPRESSION THAT
                // IS CONVERTED TO INTEGER
                alphabetIndexArray[numOfAlphabets] = i; // STORES INDEXES IN AN ARRAY WHICH WILL BE USEFUL LATER
                numOfAlphabets++;                       // INCREMENT IS DONE LATER AS INITIAL VALUE OF numOfAlphabets is 0
            }
        }

        cout << "Scan \t\t OP1 \t\t OP2 \t\t Operator \t\t Stack" << endl;
        for (int i = 0; i < MAX_LENGTH && postfixExpression[i] != '\0'; i++)
        {
            scanCh = postfixExpression[i];
            if (i == alphabetIndexArray[alphaIndex])
            {

                cout << postInt[alphaIndex] << " \t\t "; // alphaIndex is the index of number of alphabets found from 0 so it
                // increments every time an alphabet is found and can match it's contents with i in previous if case
                // and postInt will be displayed with same index
                cout << "XXX \t\t XXX \t\t XXX \t\t";
                pushToStack(postInt[alphaIndex]);
                traverse_stack();
                cout << endl;
                alphaIndex++;
            }
            else
            {
                cout << scanCh << " \t\t ";
                op1 = stack[stackTop - 1]; // PULLING VALUES FROM STACK
                cout << op1 << "  \t\t  ";
                op2 = stack[stackTop]; // PULLING VALUES FROM STACK
                cout << op2 << "  \t\t  ";
                op = scanCh; // PUTTING THE OPERATOR IN VARIABLE TO PUT IN FUNCTION AS ARGUMENT
                cout << op << "  \t\t  ";
                popFromStack(); // HAVE TO REMOVE OP1 AND OP2 FROM STACK THEN ONLY PUT VALUE IN STACK FROM operatorOperation function
                popFromStack();
                pushToStack(operatorOperation(op1, op, op2)); // PUSHES ANSWER FROM THE FUNCTION
                traverse_stack();
                cout << endl;
            }
        }
        cout<<endl;
    }
};

int main()
{
    PostEvaluator p1;
    p1.mainProcess();
}