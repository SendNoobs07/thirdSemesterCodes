#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, helper, destination);
    cout << "Moved disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1,helper,destination,source);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n,'s','d','h');
}