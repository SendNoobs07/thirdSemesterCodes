#include <iostream>

using namespace std;

int steps = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        steps++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        steps++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        steps++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        steps++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        steps++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        steps++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        steps++;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n = 10;
    int arr[n] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Total steps: " << steps << endl;

    return 0;
}
