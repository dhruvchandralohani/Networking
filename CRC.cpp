//PROGRAM FOR CRC

#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;
int main()
{
        srand(time(NULL));
        int size_gen,size_frame,y,i,j,k,l;
        cout<<"Enter the size of Generator (divisor): ";
        cin>>size_gen;

        int* gen=new int[size_gen];
        cout<<"Enter the Generator (divisor): ";
        for(i=0;i<size_gen;i++)
            cin>>gen[i];



        cout<<endl<<"Enter the size of Frame: ";
        cin>>size_frame;

        y=(size_frame+(size_gen - 1));

        int* frame=new int[y];
        cout<<"Enter the Frame: ";
        for(i=0;i<size_frame;i++)
            cin>>frame[i];

        for(i=size_frame;i<y;i++)            //Appending 0s
            frame[i]=0;



        cout<<endl<<"The Generator (divisor) is: ";
        for(i=0;i<size_gen;i++)
            cout<<gen[i];

        cout<<endl<<endl<<"The Frame is: ";
        for(i=0;i<y;i++)
            cout<<frame[i];



        int* check_sum= new int[y];
        for(i=0;i<y;i++)
            check_sum[i]=frame[i];

        //Checksum calculation
        for(i=0;i<size_frame;i++)
        {
            bool check=false;

            if(frame[i]==0)
            {
                check=true;
                //cout<<endl<<"if"<<endl;
                for(l=0;l<size_gen;l++)
                {
                    if(frame[i+l]==0)
                        frame[i+l]=0;

                    else
                        frame[i+l]=1;

                    //cout<<frame[i+l]<<" ";
                }
            }
            else
            {
                for(j=0; j<size_gen && !check; j++)
                {
                    if(frame[i+j]==gen[j])
                        frame[i+j]=0;

                    else
                        frame[i+j]=1;

                    //cout<<frame[i+j]<<" ";
                }
            }
        }

        //Adding remainder to check_sum
        for(i=size_frame;i<y;i++)
            check_sum[i]=frame[i];



        cout<<endl<<endl<<"CHECKSUM: ";
        for(i=0;i<y;i++)
            cout<<check_sum[i];



        cout<<endl<<endl<<"-----------------------------------"<<endl;
        cout<<"Sending Data..........."<<endl;
            Sleep(3000);
        cout<<endl<<"Data received."<<endl;
        cout<<"-----------------------------------"<<endl<<endl;





        //Introducing error using RAND()%20, so it MAY or MAY NOT have error.
        int r=rand()%30;
        for(i=0;i<y;i++)
        {
            if(i==r)
                check_sum[i]=!check_sum[i];
        }


        cout<<"Data word received is : ";
        for(i=0;i<y;i++)
            cout<<check_sum[i];

        cout<<endl;

        //Checking for error
        for(i=0;i<size_frame;i++)
        {
            bool check=false;

            if(check_sum[i]==0)
            {
                check=true;
                //cout<<endl<<"if"<<endl;
                for(l=0;l<size_gen;l++)
                {
                    if(check_sum[i+l]==0)
                        check_sum[i+l]=0;

                    else
                        check_sum[i+l]=1;

                    //cout<<check_sum[i+l]<<" ";
                }
            }
            else
            {
                for(j=0; j<size_gen && !check; j++)
                {
                    if(check_sum[i+j]==gen[j])
                        check_sum[i+j]=0;

                    else
                        check_sum[i+j]=1;

                    //cout<<check_sum[i+j]<<" ";
                }
            }
        }

        int sum=0;
        for(i=size_frame;i<y;i++)
            sum+=check_sum[i];

        if(sum==0)
            cout<<"No error."<<endl;

        else
            cout<<"ERROR HAS OCCURED."<<endl;

}
