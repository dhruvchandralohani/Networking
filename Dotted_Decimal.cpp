#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	int i;
	int* a;
	
	cout<<"Enter the IP Address: ";
	for(i=1;i<=4;i++)
		cin>>a[i];
		
	cout<<"Inputted IP Address is : ";
	for(i=1;i<=4;i++)
	{
		cout<<a[i];
		
		if(i!=4)
			cout<<".";
	}	
	cout<<endl;
	
	cout<<"Dotted Binary of the inputted IP Address is: ";
	for(i=1;i<=4;i++)
	{
		cout<< bitset<8> (a[i]);
		
		if(i!=4)
			cout<<".";		
	}
}
