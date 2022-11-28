//Distinguishes Odd and Even Number.
#include ".\std_lib_facilities.h"

int main()
{
    int a{0};
    cout<<"Enter The number : ";
    cin>>a;
    if(a%2==0){cout<<"\n"<<a<<" is an even number \n";}
    else{cout<<"\n"<<a<<" is an odd number \n";}
}