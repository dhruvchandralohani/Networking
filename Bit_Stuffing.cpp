//PROGRAM FOR BIT STUFFING

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    cout<<" BIT STUFFING \n";
    cout<<"Enter the data stream to stuff: ";
    string a;
    getline(cin,a);

	int i,size=0;

		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]!='0'&&a[i]!='1')
			{
				cout<<"Invalid input."<<endl;
				cout<<"Program will exit now.";
				cin.get();
				exit(0);
			}
			size++;
		}

		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='0' && a[i+1]=='1' && a[i+2]=='1' && a[i+3]=='1' && a[i+4]=='1' && a[i+5]=='1')
			{
				a.insert((i+6),0);
				i=i+6;
			}
		}

		//cout<<endl<<"Just to check: "<<a<<endl;
		cout<<endl<<"The stuffed data stream is: "<<a<<endl;

		int x=(i-size);
		cout<<"Total no. of bits stuffed = "<<x<<endl;

		cout<<endl<<"Sending Data..........."<<endl;
		cout<<endl<<"Data received."<<endl;

		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='0' && a[i+1]=='1' && a[i+2]=='1' && a[i+3]=='1' && a[i+4]=='1' && a[i+5]=='1')
			{
				a.erase((i+6),1);
			}
		}

		cout<<endl<<"The de-stuffed stream is: "<<a<<endl;
		cout<<"Total no. of bits de-stuffed = "<<x<<endl;
}
