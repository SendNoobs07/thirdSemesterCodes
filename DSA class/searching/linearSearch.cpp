#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int arr[5] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not in the array"
        : cout << "Element is at index " << result;
    return 0;
}