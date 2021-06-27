#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;
int f,r,k;
unsigned int rno,sno;
int *a, *b;
bool ack=true;
class timer
{
	private:	
	bool resetted;
	bool running;
	unsigned long beg; 
	unsigned long end;
	public:
	timer()
	{
		resetted=true;
		running=false;
		beg=0; 
		end=0;
	}
	void start()
	{
		if(!running)
		{
			if(resetted)
			{
				beg= (unsigned long) clock();
			}
			else
				beg -= end - (unsigned long) clock();
			running=true;
			resetted=false;
		}
	}
	void stop()
	{
		if(!running)
		{
			end=(unsigned long) clock();
			running=false;
		}
	}
	void reset()
	{
		bool wereRunning=running;
		if(wereRunning)
			stop();
		resetted=true;
		beg=0;
		end=0;
		if(wereRunning)
			start();
	}
	unsigned long getTime()
	{
		if(running)
			return ((unsigned long)clock() - beg);
		else
			return (end - beg);
	}
	bool isOver(unsigned long seconds)
	{
		return seconds<getTime();
	}
};
timer t;
void sender()
{
		cout<<"\nEnter the SIZE of FRAME: ";
		cin>>r;
		a=new int[r];
		sno=k%2; 
		cout<<endl<<endl;
		cout<<"\nEnter the FRAME: ";
		for(int i=0;i<r;i++)
			cin>>a[i];
		cout<<"Sno: "<<sno;
		cout<<" The FRAME is: ";
		for(int i=0;i<r;i++)
			cout<<a[i];
		cout<<endl<<endl<<endl;
		sleep(2);
		cout<<"SENDING DATA...";
		sleep(1);
		cout<<"\n"<<endl;
		ack=false;
}
void receiver()
{
	sleep(1);
		b=new int[r];
		rno=sno;
		for(int i=0;i<r;i++)
			b[i]=a[i];
		cout<<"DATA RECEIVED."<<endl;
		cout<<"Rno: "<<rno;
		cout<<" RECEIVED DATA IS: ";
		for(int i=0;i<r;i++)
			cout<<b[i];
		cout<<endl<<endl;
		ack=true;
}
void resend()
{
	sleep(1);
	cout<<endl<<endl;
	cout<<"\nTimer Expired.";
	sleep(2);
	cout<<"\nRE-SENDING DATA...";
	cout<<"\n"<<endl;
}
void func(unsigned seconds)
{
	sender();
	sleep(1);
	if(t.isOver(seconds))
	{
		t.reset();
		resend();
	}
	else
		receiver();
}
int main()
{
	cout<<"\nEnter number of FRAMES: ";
	cin>>f;
	for(k=0;k<f;k++)
	{
		if(k==0)
		{
			t.start();
			if(ack==true && rno==sno%2)
			{
				func(0.00000000000000008);
				receiver();
			}
		}
		else
		{
			ack=true;
			if(ack==true && rno==sno%2)
				func(1000000);
		}
	}
}
