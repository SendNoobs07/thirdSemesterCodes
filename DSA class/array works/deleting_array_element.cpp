#include <iostream>
using namespace std;

class Demo
{
public:
    int oldArray[7] = {2, 7, 9, 11, 10, 4, 17};
    int newArray[6];
    int e_counter = 0, o_counter = 0, n = 7, del_index = -1;
    Demo()
    {
        cout<<"Enter which nth number to delete: ";
        cin>>del_index;
        for (int i = 0; i < n; i++)
        {
            if (i == del_index - 1)
            {
                o_counter++;
            }
            else
            {
                newArray[e_counter] = oldArray[o_counter];
                e_counter++;
                o_counter++;
            }
        }
    }
    void display(){
        for(int i=0;i<6;i++){
            cout<<newArray[i]<<"   ";
        }
    }
};

int main()
{
    Demo d1;
    d1.display();
    return 0;
}