#include <iostream>
#include <unistd.h>
#include <time.h>
using namespace std;
struct frame{
	int data=0;
	int sq=0;
};
frame *ss=new frame; 
bool ak=false;
int rsq=0;
unsigned long beg=0;
void Sender(int x
){
	sleep(1);
	ss->data=x;
	if(ak==true)
		ss->sq++;
	cout<<"\n\nData Sent: "<<ss->data;
	sleep(1);
	ak=false;
}
void Receiver(frame *ss)
{
	if(ss->sq==rsq)
	{
		sleep(1);
		cout<<"\n\nData Received: "<<ss->data;
		rsq++;
		cout<<"\n\nAcknowledgment sent...!";
		ak=true;
	}
	else
	{
		sleep(2);
		cout<<"\nWrong frame";
	}
	sleep(1);
}
int main()
{
	cout<<"\nEnter no. of Frames:";
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i <n ; i++)
	{
		cout<<"\nEnter Frame "<<i<<" Data:";
		cin>>a[i];
	}
	int i=0,count=0;
	bool flag=false;
	beg=(unsigned long)clock();
	while(i<n)
	{
		Sender(a[i]);
		if((difftime(clock(),beg)<=2000 && ak) || flag)
		{
			Receiver(ss);
			cout<<"\nAcknowledgement Received!! Data SuccessFully sent!!";
			i++;
		}
		else
		{
			count++;
			if(count>2)
				flag=true;
			sleep(1);
			cout<<"\n\n Timer Expired"<<"\nNo Acknowledgment"<<"\n\n Retransmitting Data........";
			beg=(unsigned long)clock();
		}
	}
	return 0;
}
