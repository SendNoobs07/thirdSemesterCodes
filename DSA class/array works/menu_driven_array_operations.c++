#include <iostream>
using namespace std;

class DemoClass
{
private:
    int arr_length = 0, array1[10], userInput = 0;

public:
    void insert_operation()
    {
        if (arr_length == 10)
        {
            cout << "Array is full." << endl;
        }
        else
        {
            int temp_userInput;
            cout << "Enter a number to insert: ";
            cin >> temp_userInput;
            array1[arr_length] = temp_userInput;
            arr_length++;
        }
    }

    void delete_operation()
    {
        if (arr_length == 0)
        {
            cout << "Array is empty. " << endl;
        }
        else
        {
            array1[arr_length] = 0;
            arr_length--;
            cout<<"last item has been deleted"<<endl;
        }
    }

    void traverse_operation()
    {
        if (arr_length == 0)
        {
            cout << "Can't traverse as the array is empty. " << endl;
        }
        else
        {
            cout << "The contents of Array are below: "<<endl;
            for (int i = 0; i < arr_length; i++)
            {
                cout << array1[i] << endl;
            }
        }
    }

    void ascending_sort_operation()
    {
        if (arr_length == 0)
        {
            cout << "Array is empty can't sort. " << endl;
        }
        else
        {
            for (int i = 0; i < arr_length; i++)
            {
                for (int j = i + 1; j < arr_length; j++)
                {
                    if (array1[i] > array1[j])
                    {
                        int temp = array1[i];
                        array1[i] = array1[j];
                        array1[j] = temp;
                    }
                }
            }
        }
    }

    void is_empty_operation()
    {
        if (arr_length == 0)
        {
            cout << "The array is empty." << endl;
        }
        else
        {
            cout << "The array has some element/elements. " << endl;
        }
    }

    void is_full_operation()
    {
        if (arr_length >= 10)
        {
            cout << "The array is full." << endl;
        }
        else
        {
            cout << "The array is not full." << endl;
        }
    }

    void merge_operation()
    {
        int temp_userInput = 0;
        cout << "Enter number of elements to merge:";
        cin >> temp_userInput;
        int temp_arr[temp_userInput];

        if (arr_length + temp_userInput > 10)
        {
            cout << "The array might not be able to merge all elements.";
        }
        else
        {
            cout << "Enter elements to merge:" << endl;
            for (int i = 0; i < temp_userInput; i++)
            {
                cout << "Element " << i + 1 << ": ";
                cin >> temp_arr[i];
            }

            int loop_counter = 0;
            for (int i = 0; i < temp_userInput; i++)
            {
                array1[arr_length + i] = temp_arr[i];
                loop_counter++;
            }
            arr_length += loop_counter;
        }
    }

    void take_user_choice()
    {
        int operation_number = 0;
        do
        {
            cout << "\nSelect any operation from the choices below: " << endl;
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Traverse" << endl;
            cout << "4. Sorting" << endl;
            cout << "5. Check if array is empty" << endl;
            cout << "6. check if array is full" << endl;
            cout << "7. Merge two arrays" << endl;
            cout << "8. EXIT" << endl << endl;
            cin >> operation_number;
            switch (operation_number)
            {
            case 1:
            	cout<<endl;
                insert_operation();
                break;

            case 2:
            	cout<<endl;
                delete_operation();
                break;

            case 3:
            	cout<<endl;
                traverse_operation();
                break;

            case 4:
            	cout<<endl;
                ascending_sort_operation();
                break;

            case 5:
            	cout<<endl;
                is_empty_operation();
                break;

            case 6:
            	cout<<endl;
                is_full_operation();
                break;

            case 7:
            	cout<<endl;
                merge_operation();
                break;

            case 8:
            	cout<<endl;
                cout << "Exiting Program" << endl;
                break;

            default:
            	cout<<endl;
                cout << "Select a number again!!";
                break;
            }
        } while (operation_number != 8);
    }
};

int main()
{
    DemoClass d1;
    d1.take_user_choice();
    return 0;
}