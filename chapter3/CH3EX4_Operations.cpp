// small no.,sum,difference,product,ratio of two integers
#include ".\std_lib_facilities.h"

int main()
{
    double val1;
    double val2;
    int smaller,larger;
    int sum, prod, diff;
    double ratio;
    while(cout<<" Insert two number (type Space Between them - ) : " && cin>>val1>>val2)
    {
        if(val1<val2){smaller=val1;larger=val2;}
        else{smaller=val2;larger=val1;}
        sum=val1+val2;
        diff=larger-smaller;
        prod=val1*val2;
        
        //Ratio can be decimal, so values must be of type:double.
        ratio=val1/val2;

        cout<<"\n"<<smaller<<" is the smaller number while "<<larger <<" is the larger number";
        cout<<"\n sum : "<<sum
        <<"\n difference : "<<diff
        <<"\n product : "<< prod
        <<"\n ratio (num1/num2) : "<<ratio;
        cout<<"\n ------ END-RESTART ------ \n";
    }
}