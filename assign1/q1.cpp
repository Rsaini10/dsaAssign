#include <iostream>
using namespace std;
int arr[1000];

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
        cout<<"enter element";
        cin>>ele;
        arr[i]=ele;
    }
}
void display(){
    cout<<"below is the array"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void insert(){
    int index;
    int element;
    cout<<"which element do you want to store?";
    cin>>element;
    cout<<"at which index do you want to insert element?";
    cin>>index;
    for(int i=length;i>=index;i--){
        arr[i]=arr[i-1];
    }
    length++;
    arr[index]=element;

}
void deleted(){
    int index;
    cout<<"which index do you want to delete?"<<endl;
    cin>>index;
     for(int i=index;i<length-1;i++){
        arr[i]=arr[i+1];
    }
    length--;
    
}
void linearsearch(){
    int element;
    int found=0;
    cout<<"which element do you want to find?";
    cin>>element;
    for(int i=0;i<length;i++){
        if(arr[i]==element){
            cout<<"found the element at index "<<i;
            found =1;
            break;
        }
        
    }
    if(found==0){
        cout<<"not found"<<endl;
    }

}

int main()
{
    int cmd;
    while(true){
    cout<<"in order to create press 1"<<endl;
    cout<<"in order to display press 2"<<endl;
    cout<<"in order to insert press 3"<<endl;
    cout<<"in order to delete press 4"<<endl;
    cout<<"in order to do linear search press 5"<<endl;
    cout<<"in order to exit press 0"<<endl;
    cout<<"enter:";
    cin>>cmd;
    switch(cmd){
        case 1:
        create();
        break;
        case 2:
        display();
        break;
        case 3:
        insert();
        break;
        case 4:
        deleted();
        break;
        case 5:
        linearsearch();
        break;
        case 0:
        exit(0);
    }
}

    return 0;
}