#include <iostream>
using namespace std;
int arr[100];

int length;
void setlength()
{
    cout << "how many elements do you want in your array?";
    cin >> length;
}
void create()
{
    int ele;
    setlength();
    for (int i = 0; i < length; i++)
    {
        cout << "enter element";
        cin >> ele;
        arr[i] = ele;
    }
}
void display()
{
    cout << "below is the array" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void search()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < length - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                length--;
                j--;//here 
            }
        }
    }
}

int main()
{
    create();
    display();
    search();
    display();
    return 0;
}