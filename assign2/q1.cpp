#include<iostream>
using namespace std;
int main()
{	
	int n;
	cout<<"Enter the number of array elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int find;
	cout<<"Enter the element to be found";
	cin>>find;
	
	int beg=0,end=n-1,mid;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==find)
		{
		cout<<("x found at",mid);
		break;
		}
		else if(find>a[mid])
		{
			beg=mid+1;
			
		}
		else{
			end=mid-1;
		}
	}
}