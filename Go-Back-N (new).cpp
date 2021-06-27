#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define MAX 30
using namespace std;
struct frame
{
	int data;
	int sq;
};
int n=0,acno=1;
bool ack=true;
frame *ss=new frame;
void Sender(int x,bool ack, int acno)
{
	static bool first=true;
	if(ack)
		ss->sq++;
	if(ss->sq==acno || first)
	{
		first=false;
		ss->data=x;
		cout<<"\nSender:Data sent:"<<ss->data<<"\t sq no.:"<<ss->sq;
		ack=false;
	}
	sleep(1);
}
void Receiver(frame *ss)
{
	if (ss->sq==acno)
	{
		cout<<"\nReceiver:Data Received!!....Sending Acknowledgment\n";
		ack=true;
		acno++;
	}
}
int main()
{
	cout<<"Enter no. of frames:";
	cin>>n;
	cout<<"\nEnter size of window:";
	int ws=0;
	cin>>ws;
	int a[MAX];
	for (int i = 0; i < n; ++i)
	{
		cout<<"\nEnter data of frame "<<i+1<<":";
		cin>>a[i];
	}
	int k=1,count=0,timer=rand()%1000;
	bool reset=false,go=false;
	unsigned long beg=clock();
	srand(time(0));
	for (int i = 0; i < n;)
	{
		cout<<"\nWindow "<<k;
		for (int j = i; j < i+ws && j<n; ++j)
		{
			Sender(a[j],ack,acno);
			if(difftime(clock(),beg)<=timer || go)
				Receiver(ss);
			else
			{
				ack=false;
				cout<<"\nTimer Expired\n";
				count++;
				if(count>2)
					go=true;
				reset=true;
			}
		}
		if(reset)
			reset=false;
		else
		{
			i+=ws;
			k++;
		}
	}
	return 0;
}

