#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;
int main()
{
	int count=0,count1=0;
	char bit;
	string a;
	cout<<"\nENTER THE DATA STREAM: ";
	while(cin.get(bit) && (bit=='0' || bit=='1'))
	{
		a+=bit;
		if(bit==('\r'))
			break;
	}
	cout<<"\nTHE DATA-STREAM IS: "<<a;
	int n=a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]=='0')
		{
			if(a[i+1]=='1' && a[i+2]=='1' && a[i+3]=='1' && a[i+4]=='1' && a[i+5]=='1')
			{
				a.insert(i+6,"0");
				i+=6;
				count++;
			}
		}
	}
	cout<<"\nTHE STUFFED DATA-STREAM IS: "<<a;
	cout<<"\n\nTOTAL NUMBER OF BITS STUFFED: "<<count;
	cout<<"\n\n*********************";
	cout<<"\nSENDING DATA TO RECEIVER.";
	cout<<"\n*********************";
	sleep(3);
	cout<<"\nDATA RECEIVED";
	cout<<"\n*********************";
	int m=a.length();
	for(int i=0;i<m;i++)
	{
		if(a[i]=='0')
		{
			if(a[i+1]=='1' && a[i+2]=='1' && a[i+3]=='1' && a[i+4]=='1' && a[i+5]=='1')
			{
				a.erase(i+6,1);
				count1++;
			}
		}
	}
	cout<<"\n\nTHE DESTUFFED DATA-STREAM IS: "<<a;
	cout<<"\n\nTOTAL NUMBER OF BITS DESTUFFED: "<<count1;
	return 0;
}
