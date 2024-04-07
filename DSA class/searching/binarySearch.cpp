#include <iostream>
using namespace std;

int arr[10] = {0, 2, 4, 5, 6, 9, 54, 55, 69, 99};

int binarySearch(int low, int high, int key)
{
    int mid = (high + low) / 2;
    cout << endl
         << "new mid is : " << mid << endl
         << "new h is : " << high << endl
         << "new l is : " << low << endl;
    cout << arr[mid] << " and " << key << endl;
    if (low == high)
    {
        return -1;
    }
    else if (arr[mid] < key)
    {
        int temp = binarySearch(mid + 1, high, key);
        return (temp == 1)? 1 : -1;
        
    }
    else if (arr[mid] > key)
    {
        int temp = binarySearch(low, mid - 1, key);
        return (temp == 1)? 1: -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int user;
    cout << "Enter a number to search in the array: ";
    cin >> user;
    int result = binarySearch(0, 9, user);
    (result == 1) ? cout << endl << "Key was found." << endl : cout << endl << "Key wasn't found." << endl;
}