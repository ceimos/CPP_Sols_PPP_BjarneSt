#include ".\std_lib_facilities.h"

int main()
{
    string a{"zero"};string b{"zero"};
    char oper{'+'};
    double result;
    vector<string> num_spelled={"zero","one","two","three","four","five","six","seven","eight","nine"};
    double a_spell; double b_spell;

    while(cout<<"Enter two number(spelled) followed by any operation(+,-,*,/) : " && cin>>a>>b>>oper)
    {
        bool found{false};
        for(int i{0};i<num_spelled.size();++i){
            if(num_spelled[i]==a){
                a_spell=i;
                found=true;
                break;}} 

        if(found=false){cout<<"wrong iput try again \n";continue;}
        else{
            for(int i{0};i<num_spelled.size();++i){
                if(num_spelled[i]==b){
                    b_spell=i;
                    found=true;
                    break; } }
            if(found=false){cout<<"Wrong Input Try agian \n"; continue;}}


        if(oper=='+'){result=a_spell+b_spell;}
        else if(oper=='-'){result=a_spell-b_spell;}
        else if(oper=='*'){result=a_spell*b_spell;}
        else if(oper=='/'){result=a_spell/b_spell;}
        else{cout<<"Wrong Input Try Again! Choose Among \" +   -   *   / \" ";result=0;}

        cout<<"\nResult is :  "<<result<<" \n";
    }
}