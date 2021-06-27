#include <iostream>
#include <time.h>
#include <unistd.h>
#define MAX 30
using namespace std;
struct frame
{
	int data;
	int sq;
	bool isSent;
};
frame *rs=new frame[MAX];
int n=0,rscount=0;
void Sender(frame *s)
{
	cout<<"\nSender: Data:"<<s->data<<" sq:"<<s->sq;
	sleep(2);
}
void Receiver(frame *r)
{
	r->isSent=true;
	rs[rscount].data=r->data;
	rs[rscount].sq=r->sq;
	rs[rscount].isSent=r->isSent;
	cout<<"\nReceiver:Data Received:"<<rs[rscount].data<<" sq:"<<rs[rscount].sq<<" Sending Acknowledgment and Acknowledgment number";
}
int main()
{
	int ws=0,k=0;
	cout<<"Enter no. of Frames:";
	cin>>n;
	cout<<"\nEnter window size:";
	cin>>ws;
	frame *a=new frame[MAX];
	for (int i = 0; i < n; ++i)
	{
		a[i].sq=i+1;
		cout<<"\nEnter data for frame "<<a[i].sq<<":";
		cin>>a[i].data;
		a[i].isSent=false;
	}
	int count2=0,count3=0;
	bool reset=false,go=false;
	unsigned long beg=clock();
	for (int i = 0; i <n;)
	{
		cout<<"\nWindow "<<++k<<"\n------";
		for (int j = i; j <ws+i+count2 && j<n; j++)
		{
			if(!a[j].isSent)
			{
				Sender(&a[j]);
				cout<<"\n"<<difftime(clock(),beg);
				if(difftime(clock(),beg)<=500 || go)
					Receiver(&a[j]);
				else
				{
					cout<<"Timer Expired";
					count3++;
					if(count3==1)
						go=true;
					reset=true;
				}
			}
			else
			{
				cout<<"\nelse";
				count2++;
			}
		}
		if(reset)
			reset=false;
		else
		{
			i+=(ws+count2);
		}
	}
	return 0;
}

