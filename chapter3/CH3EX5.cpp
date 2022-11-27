// smaller no.,sum,difference,product,ratio of two integers
// modified EX4 to accept float rather than double.
#include ".\std_lib_facilities.h"

int main()
{
    float val1 {0};
    float val2 {0};
    int smaller,larger;
    int sum, prod, diff;
    double ratio;
    while(cout<<" Insert two number (type Space Between them - ) : " && cin>>val1>>val2)
    {
        //convert the values to type:double
        double v1=val1;
        double v2=val2; //if values not initialized earlier it will say "undefined values are used." 
        //So, I initialized them, where i declared val1 val2 first (line7).
        //for, some reason it gives out garbage value if I not do that.
        cout<<v1<<" "<<v2; 
        if(v1<v2){smaller=v1;larger=v2;}
        else{smaller=v2;larger=v1;}
        sum=v1+v2;
        diff=larger-smaller;
        prod=v1*v2;
        
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