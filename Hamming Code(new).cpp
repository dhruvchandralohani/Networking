#include <iostream>
#include <math.h>
#include <bitset>
#include <string.h>
#define MAX 100
using namespace std;
int *data2;				//for new codeword with redundant bits
int parity(int l,int r,int x)		//to count parity for the redundant bits
{
	int count=0;
	for (int i = 1; i <= l; i++)
	{
		string s=bitset<MAX>(i).to_string();
		s.erase(0,s.length()-r);
		if(s[r-x]=='1')
		{
			if(data2[i]==1 && i!=pow(2,x-1))
			{
				count++;
			}
		}
	}
	return (count%2==0?0:1);
}
int main()
{
	int n;
	cout<<"Enter no. of bits:";
	cin>>n;
	int r=1;
	int data[MAX];
	cout<<"\nEnter Data (1's or 0's):";
	for (int i = 1; i <=n ; i++)
	{
		cin>>data[i];
	}
	while((pow(2,r))<(n+r+1))
		r++;
	cout<<"\nNo. of Redundant Bits:"<<r;
	cout<<"\n";
	int l=n+r;
	data2=new int[MAX];
	for (int i = 0; i <=r && pow(2,i)<=l ; i++) //to insert 2 in place of redundant bits
	{
		if((int)pow(2,i)==1)
			data2[1]=2;
		else
			data2[(int)pow(2,i)]=2;
	}
	for (int i = 1,j=1; i <=n ;j++)
	{
		if(data2[j]==2);
 		else
 		{
			data2[j]=data[i];
			i++;
		}
	}
	cout<<"\n";
	int rb[MAX];
	for (int i = 1; i <=r ; i++)
		rb[i]=parity(l,r,i);
	for (int i = 1,j=1; i <= l; i++)
		if(data2[i]==2)
		{
			data2[i]=rb[j];
			j++;
		}
	cout<<"\n";
	for (int i = 1; i <= r; i++)
	{
		cout<<"r"<<i<<": "<<rb[i]<<"\n";
	}
	cout<<"\n";
	for (int i = 1; i <= l; i++)
		cout<<data2[i]<<"\t";
}
