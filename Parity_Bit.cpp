//PROGRAM FOR PARITY BIT

#include<iostream>
#include<windows.h>
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
    int size,i;
    cout<<"Enter the size of the codeword: ";
    cin>>size;

    int a[size], b[size+1];
    cout<<"Enter codeword: ";

    for(i=0;i<size;i++)
        cin>>a[i];

    int x=a[0];
    for(i=1;i<size;i++)
    {
        x=x^a[i];

    }
    cout<<"Parity bit: "<<x<<endl;


    cout<<"Dataword: ";

    for(i=0;i<size;i++)
    {
		b[i]=a[i];
		cout<<b[i];
	}
    b[i]=x;
    cout<<b[i]<<endl;



    cout<<endl<<endl<<"-----------------------------------"<<endl;
    cout<<"Sending Data..........."<<endl;
            Sleep(3000);
    cout<<endl<<"Data received."<<endl;
    cout<<"-----------------------------------"<<endl<<endl;




    //INTRODUCING ERROR USING RAND()%10, so it MAY or MAY NOT have error.
	int r=rand()%10;
	for(i=0;i<size+1;i++)
	{
		if(i==r)
			b[i]=!b[i];
	}

	cout<<endl<<"Data word received is : ";

	for(i=0;i<size+1;i++)
		cout<<b[i];

	cout<<endl;

	x=b[0];
	for(i=1;i<size+1;i++)
		x=x^b[i];


	if(x==0)
		cout<<"No error."<<endl;

	else
		cout<<"ERROR HAS OCCURED."<<endl;

}
