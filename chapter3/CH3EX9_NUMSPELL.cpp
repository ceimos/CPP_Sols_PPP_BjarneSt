//converts spelled out number to digits for numbers 0-4.
#include ".\std_lib_facilities.h"

int main()
{
    string num{" "};
    cout<<"Enter your Number : ";
    cin>>num;
    if(num=="zero"|num=="ZERO"){cout<<"\n Number is : 0 \n";}
    if(num=="one"|num=="ONE"){cout<<"\n Number is : 1 \n";}
    if(num=="two"|num=="TWO"){cout<<"\n Number is : 2 \n";}
    if(num=="three"|num=="THREE"){cout<<"\n Number is : 3 \n";}
    if(num=="four"|num=="FOUR"){cout<<"\n Number is : 4 \n";}
}