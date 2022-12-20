#include ".\std_lib_facilities.h"

int factorial(int a)
{
    int factorial_result=1;
    if(a==0){return factorial_result;}
    for(int i=1;i<=a;++i)
    {
        factorial_result*=i;
    }
    return factorial_result;
}

int permutation(int a, int b)
{
    int perm_result=factorial(a)/factorial(a-b);
    return perm_result;
}

int combination(int a,int b)
{
    int comb_result=permutation(a,b)/factorial(b);
    return comb_result;
}

void input_check(int a, int b)
{
    if(a<0 ||b<0){cout<<"Please Enter positive numbers.";}
}

int main()
{
    char operation_type;
    cout<<"What you wanna do? - Combination(c) or Permutation(p) : ";
    cin>>operation_type;

    int sample_set; int selection_set;
    cout<<"Enter the number of object in super set then number of objects to select : ";
    cin>>sample_set>>selection_set;

    input_check(sample_set,selection_set); // checks for positive number.
    if(sample_set<selection_set)
    {int c=sample_set;sample_set=selection_set;selection_set=c;
    cout<<"cannot select more from less, hence swapping the values. \n";}

    if(operation_type=='c'||operation_type=='C')
    {
        cout<<selection_set<<" objects selected from "<<sample_set<<" without importance to order has : "<<combination(sample_set,selection_set)<<" combinations.\n";
    }    
    else if(operation_type=='p'||operation_type=='P')
    {
        cout<<selection_set<<" objects selected from "<<sample_set<<" with importance to order has : "<<permutation(sample_set,selection_set)<<" permutations.\n";
    }
    else{cout<<"Operation not supported.";}
}