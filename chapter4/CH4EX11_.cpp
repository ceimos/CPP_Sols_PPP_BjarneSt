//FIND Prime numbers between 1 and 100
//ERROR FIX ERROR AFTER LEARNING ABOUT ERRORS.

#include ".\std_lib_facilities.h"

vector<int> primes{2};

int main()
{
try
{
    for(int i{3};i<=100;++i)
    {
        for(int z{0};z<primes.size();++z)
        {
            if(i%primes[z]==0){}
            else{primes.push_back(i);}
        }
    }
    cout<<"There Are : "<<primes.size()<<" Primes Between 1 and 100 \nAnd They are :- \n";
    for(int i:primes){cout<<i<<"  ";}
    cout<<"\n";
}//try closing curly
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
	cout << e.what() << '\n';
}
}