//Solves quadratic Equations 
#include "./std_lib_facilities.h"

int main()
{
    double a{0}; double b{0}; double c{0};
    
    cout<<"Quadratic equation - ax^2+bx+c=0 \n \n -------- \n \n";
    while(cout<<"Enter three number a,b,c : "&&cin>>a>>b>>c)
    {
        double D=(b*b)-(4*a*c);//discriminant
        if(D<0)
        {
            cout<<"the roots are imaginary. So, actual answer might vary \n";
        }
        double x_1=((-b)+sqrt(D))/2*a;
        double x_2=((-b)-sqrt(D))/2*a;
        cout<<"Roots are : \n";
        cout<< x_1 <<" and "<<x_2<<"\n \n";
    }
}