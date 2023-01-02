#include <iostream>
using namespace std;

void swap_v(int a,int b)
{
    int temp;

    cout<<"\nInput values are a = "<<a<<" b = "<<b;
    temp=a;
    a=b;
    b=temp;

    cout<<"\n swapped values are a = "<<a<<" b = "<<b <<"\n \n";
}

void swap_r(int& a, int& b)
{
    int temp;
    cout<<"\nInput values are a = "<<a<<" b = "<<b;
    temp=a; a=b; b=temp;
    cout<<"\n swapped values are a = "<<a<<" b = "<<b<<"\n \n";
}

void swap_cr(const int& a, const int& b)
{
    int temp; temp=a;
    cout<<"\nInput Values - a = "<<a<<" b="<<b<<"\n";
    //a=b; //WILL NOT WORK BECAUSE CANNOT ASSIGN TO CONSTANT
    int c;c=b; //now treat c as a
    int d;d=a; //treat d as b
    cout<<"Swapped Values  - a is : "<<c<<" \t b is : "<<d<<"\n \n";
}

int main()
{
    int x=7; int y=9;

    swap_r(x,y);
    swap_v(7,9);

    const int cx=7; const int cy=9;

    swap_cr(cx,cy);
    swap_v(cx,cy);

    swap_v(7.7,8.7);

}