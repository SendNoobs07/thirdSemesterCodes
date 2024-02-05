#include <iostream>
#define MAX_LENGTH 30
using namespace std;

// New things in PostFixer
/*1) substituted top instead of length
  2) renamed user_expression to expression
  3) renamed post_stack_displayer to traverse_post_stack
  4) same as num 3 for op_stack
  5) renamed class as PostFixer to Converter
  6) now can convert to both infix to postfix along with infix to prefix
  7) Program is now menu driven
  8) Flexible max length if needed
  */

class Converter
{
public:
    char on_scan_ch;
    char expression[MAX_LENGTH], post_stack[MAX_LENGTH], op_stack[MAX_LENGTH];
    int op_stack_top = -1, post_stack_top = -1, infix_expression_top = -1, final_index = 0, userChoice = 0;

    // CONSTRUCTORS
    Converter()
    {
        cout << "Enter an expression: ";
        cin >> expression;
        for (int i = 0; i < MAX_LENGTH && expression[i] != '\0'; i++)
        {
            if (expression[i + 1] == '\0')
            {
                final_index = i + 1;
            }
        }
    }
    Converter(char temp_ch[MAX_LENGTH])
    {
        for (int i = 0; i < MAX_LENGTH && expression[i] != '\0'; i++)
        {
            if (expression[i + 1] == '\0')
            {
                final_index = i + 1;
            }
            expression[i] = temp_ch[i];
        }
    }

    // USED FUNCTIONS

    int precedence_provider(char ch)
    {
        switch (ch)
        {
        case '$':
            return 3;
            break;

        case '*':
        case '/':
            return 2;
            break;

        case '+':
        case '-':
            return 1;
            break;

        default:
            return 0;
            break;
        }
        return 0;
    }

    void push_alphabet()
    {
        post_stack_top++;
        post_stack[post_stack_top] = on_scan_ch;
    }

    void push_operator()
    {
        op_stack_top++;
        op_stack[op_stack_top] = on_scan_ch;
    }

    void op_stack_to_post_stack_cause_bracket()
    {
        while (op_stack[op_stack_top] != '(')
        {
            post_stack_top++;
            post_stack[post_stack_top] = op_stack[op_stack_top];
            op_stack_top--;
        }
        // Mathi ko ma somehow '(' always remains cause while exits when !- '(' and top doesn't decrease which 
        // leads to '(' remaining in op stack so we use if condition below to remove the final '('
        if (op_stack[op_stack_top] == '(')
        {
            --op_stack_top;
        }
    }

    void op_stack_to_post_stack_cause_precedence()
    {
        for (int i = op_stack_top; i > -1; i--)
        {
            // If bracket comes then stop the stack transfer operation
            if (op_stack[i] == '(')
            {
                break;
            }
            // else it just continues as it is supposed to
            else
            {
                post_stack_top++;
                post_stack[post_stack_top] = op_stack[op_stack_top];
                op_stack_top--;
            }
        }
    }

    void traverse_post_stack()
    {
        // i starts from zero then stops when it is equal to value of top of post_stack
        for (int i = 0; i <= post_stack_top; i++)
        {
            cout << post_stack[i];
        }
        // leaving 2 tabs so it will be easier to display in table view
        cout << "\t\t";
    }

    void traverse_op_stack()
    {
        // i starts from zero then stops when it is equal to value of top of op_stack
        for (int i = 0; i <= op_stack_top; i++)
        {
            cout << op_stack[i];
        }
        // op-stack is in last column so endl is necessary
        cout << endl;
    }

    void infix_to_postfix()
    {
        // Table headings
        cout << "Scan_Stack\tPost_Stack\tOp_Stack" << endl;

        // initializing q to manipulate while loop
        int q = 0;
        // while loop runs till q is less than final_index (final index contains '\0')
        while (q < final_index)
        {
            // putting characters one by one to on_scan_ch via while loop
            on_scan_ch = expression[q];
            // leaving two tabs for clear readability
            cout << on_scan_ch << "\t\t";
            // converting character from character to integer to compare the ascii values and recognize alphabets
            int temp_ch = int(on_scan_ch);

            // CHECKING IF TEMP_CH IS AN ALPHABET
            if ((temp_ch >= 65 && temp_ch <= 90) || (temp_ch >= 97 && temp_ch <= 122))
            {
                // This condition works if scanned character is an alphabet
                push_alphabet();
            }

            // CHECK IF TEMP_CH IS ' ) '
            else if (temp_ch == ')')
            {
                // this function pushes contents of op_stack to post_stack if ')' is found and does so until '(' is found which
                // is in function defintion
                op_stack_to_post_stack_cause_bracket();
            }
            // CHECK IF TEMP_CH IS ' ( '
            else if (temp_ch == '(')
            {
                op_stack_top++;
                op_stack[op_stack_top] = temp_ch;
                // puts '(' on top of op_stack
            }
            // IF THE CHARACTER IS NOT AN ALPHABET, NOT A BRACKET THEN IT WILL BE AN OPERATOR WHICH WILL BE HANDLED IN THIS CASE
            else
            {
                // FIRST WE HAVE TO CHECK PRECEDENCE OF OPERATOR THAT IS ALREADY IN op_stack
                if (precedence_provider(op_stack[op_stack_top]) > precedence_provider(temp_ch))
                {
                    op_stack_to_post_stack_cause_precedence();
                }
                // IF PRECEDENCE PROBLEM IS SOLVED THAN TEMP_CH(i.e: q) IS PUSHED
                push_operator();
            }
            traverse_post_stack();
            traverse_op_stack();
            q++; // incrementing q each time by 1 for while loop
        }
        while (op_stack_top > -1) // To make sure all characters of op_stack are pushed to post_stack
        {
            post_stack_top++;
            post_stack[post_stack_top] = op_stack[op_stack_top];
            op_stack_top--;
        }
        cout << endl
             << "FINAL POSTFIX EXPRESSION : ";
        traverse_post_stack();
        cout << endl;
    }

    void infix_to_prefix()
    {
        char rev1[MAX_LENGTH], rev2[MAX_LENGTH];
        // REVERSING FOR THE FIRST TIME BEFORE POSTFIX CONVERSION
        for (int i = 0; i < final_index; i++)
        {
            if (expression[i] == '(')
            {
                rev1[final_index - (i + 1)] = ')';
            }

            else if (expression[i] == ')')
            {
                rev1[final_index - (i + 1)] = '(';
            }

            else
            {
                rev1[final_index - (i + 1)] = expression[i];
            }
        }

        // OVERWRITING VALUES OF REV1 TO array expression[i] as it will be used in
        // function infix to postfix and not rev1
        for (int i = 0; i < final_index; i++)
        {
            expression[i] = rev1[i];
        }

        // CONVERTING TO PREFIX
        infix_to_postfix();

        // REVERSING FOR THE LAST TIME TO GET THE FINAL ANSWER
        for (int i = 0; i <= post_stack_top; i++)
        {
            rev2[post_stack_top - i] = post_stack[i];
        }

        // FINALLY DISPLAYING THE RESULT
        cout << "FINAL PREFIX EXPRESSION : ";
        for (int i = 0; i <= post_stack_top; i++)
        {
            cout << rev2[i];
        }
        cout << endl;
    }

    void main_process()
    {
        do
        {
            cout << "Choose an operation from below : " << endl;
            cout << " 1 ) Postfix" << endl;
            cout << " 2 ) Prefix" << endl;
            cout << " 3 ) Exit" << endl;
            cin >> userChoice;

            switch (userChoice)
            {
            case 1:
                infix_to_postfix();
                break;

            case 2:
                infix_to_prefix();
                break;

            case 3:
                cout << "Exiting program ..." << endl;
                break;

            default:
                cout << "Invalid input please try again!!..." << endl;
                break;
            }
        } while (userChoice != 3);
    }
};

int main()
{
    Converter c1;
    c1.main_process();
}