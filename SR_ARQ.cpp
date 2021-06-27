#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;
int z=11;
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
				beg= (unsigned long) clock();
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
			return z--;
		else
			return (end - beg)/CLOCKS_PER_SEC;
	}
	bool isOver(unsigned long seconds)
	{
		return seconds<getTime();
	}
};
int n,w,l,k;
class frame: public timer
{
	public:
	int *a, *b;
	bool ack=true;
	bool r_flag=false;
	unsigned int rno,sno;
	int size;
	void sender()
	{
		cout<<"\nEnter the SIZE of FRAME: ";
		cin>>size;
		a=new int[size];
		if(l<w)
			sno=l; 
		else
			sno=k%w;
		cout<<"\nEnter the FRAME: ";
		for(int i=0;i<size;i++)
			cin>>a[i];
		cout<<"\nSno: "<<sno;
		cout<<" The FRAME is: ";
		for(int i=0;i<size;i++)
			cout<<a[i];
		cout<<endl<<endl<<endl;
		sleep(2);
		cout<<"\n"<<endl;
		ack=false;
	}
	void receiver()
	{
		sleep(1);
		b=new int[size];
		rno=sno;
		for(int i=0;i<size;i++)
			b[i]=a[i];
		//cout<<"DATA RECEIVED."<<endl;
		cout<<"\nRno: "<<rno;
		cout<<" RECEIVED DATA IS: ";
		for(int i=0;i<size;i++)
			cout<<b[i];
		cout<<endl<<endl;
		ack=true;
	}
	void resend()
	{
		cout<<"\nSno: "<<sno;
		cout<<" The FRAME is: ";
		for(int i=0;i<size;i++)
			cout<<a[i];
		sleep(1);
		cout<<endl<<endl;
		sleep(2);
		ack=false;
	}
	void func(unsigned long seconds)
	{
		sender();
		sleep(1);
		if(isOver(seconds))
		{
			reset();
			resend();
		}
	}
}*f;
int main()
{
	unsigned long seconds=10;
	cout<<"\nEnter number of FRAMES: ";
	cin>>n;
	f=new frame[n];
	cout<<"\nEnter size of WINDOW: ";
	cin>>w;
	int i;
	for(i=0,k=w;i<(n-w+1);i++)
	{
		if(i==0)
		{
			for(l=0;l<w;l++)
			{
				f[l].start();
				if(f[l].ack==true && f[l].rno==f[l].sno)
					f[l].sender();
			}
			cout<<"SENDING DATA...";
			for(int j=0;j<w;j++)
			{
				if(f[j].isOver(seconds))
				{
					f[j].reset();
					f[j+1].receiver();
					cout<<"Timer expired.";
					sleep(1);
					cout<<"\nSno. 0 Not Received";
					cout<<"\nRE-SENDING DATA...";
					f[j].receiver();
				}
				else
				{
					if(j!=1)
						f[j].receiver();
				}
			}
		}
		else
		{
			if(f[k].ack==true && f[k].rno==f[k].sno)
			{
				f[k].start();
				f[k].func(seconds);
				f[k+1].sno=1;
				f[k+1].func(seconds);
				f[k].receiver();
				f[k+1].receiver();
			}
			k=k+2;
		}
	}
}
