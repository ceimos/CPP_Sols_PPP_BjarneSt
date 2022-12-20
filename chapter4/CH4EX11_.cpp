//FIND Prime numbers between 1 and 100

#include ".\std_lib_facilities.h"

vector<int> primes{2};//Smallest prime.


bool in(int i)
{
    bool is_in=false;
    for(int a : primes)
    {
        if(i==a){is_in=true; break;}
    }
    if(is_in==true){return true;}
    else return false;
}


bool is_prime(int i)
{
    for(int a:primes){if(i%a==0){return false;}}
    return true; // return can be used here because, return terminates the function call.
    /*if the "if" is triggered in for loop then the return statement outside the for loop won't be executed.*/
}


int main()
{
    for(int i{3};i<=100;++i){if(is_prime(i)==true){primes.push_back(i);}}
    
    cout<<"There Are : "<<primes.size()<<" Primes Between 1 and 100 \nAnd They are :- \n";
    for(int i:primes){cout<<i<<"  ";}
    cout<<"\n";
}