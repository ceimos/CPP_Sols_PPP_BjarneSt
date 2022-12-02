#include ".\std_lib_facilities.h"

int main()
{
    double a{0};double b{0};
    char oper{'+'};
    double result;

    while(cout<<"Enter two number followed by any operation(+,-,*,/) : " && cin>>a>>b>>oper)
    {
        if(oper=='+'){result=a+b;}
        else if(oper=='-'){result=a-b;}
        else if(oper=='*'){result=a*b;}
        else if(oper=='/'){result=a/b;}
        else{cout<<"Wrong Input Try Again! Choose Among \" +   -   *   / \" ";result=0;}

        cout<<"\nResult is :  "<<result<<" \n";
    }
}