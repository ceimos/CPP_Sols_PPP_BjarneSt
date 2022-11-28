//Binary Operations
//Usage :- operation operand_one operand_two
#include ".\std_lib_facilities.h"

int main()
{
    char operation{'+'};
    double a{0.0};
    double b{0.0};
    double result;
    bool wrong_input {false};

    cout<<"Usage :- operation operand_one operand_two"
    <<"\n Please give in line below :- \n";

    cin>>operation>>a>>b;
    //operations --
    if(operation=='+'){result=a+b;}
    else if(operation=='-'){result=fabs(a-b);} //Fabs is like f(x)=|x| (modulus) function in maths.Returns unsigned value. 
    else if(operation=='*'){result=a*b;}
    else if(operation=='/'){result=a/b;}
    else{cout<<"Wrong Input \n";wrong_input=true;} //if doesnt pass above statements then input is assumed to be wrong.
    //outputs result only if inputs are right.
    if(wrong_input==false){cout<<"Result == "<<result<<"\n";}
}