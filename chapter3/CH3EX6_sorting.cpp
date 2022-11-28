//shorts three integers in ascending order.
#include ".\std_lib_facilities.h"

int main()
{
    int a {0} ,b {0},c {0};
    cout<<"Enter three numbers : ";
    cin>>a>>b>>c;
    cout<<"\n In Asceding order :- ";
    if(a>b)
    {
        if(b>c){cout<<"\n"<<c<<" "<<b<<" "<<a;}
        else
        {
            if(a>c){cout<<"\n"<<b<<" "<<c<<" "<<a;}
            else{cout<<"\n"<<b<<" "<<a<<" "<<c;}
        }
    }
    else
    {
        if(b<c){cout<<"\n"<<a<<" "<<b<<" "<<c;}
        else
        {
            if(a>c){cout<<"\n"<<c<<" "<<a<<" "<<b;}
            else{cout<<"\n"<<a<<" "<<c<<" "<<b;}
        }
    }
    cout<<"\n";
}
