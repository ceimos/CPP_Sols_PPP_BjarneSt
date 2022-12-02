#include ".\std_lib_facilities.h"

int main()
{
    double i;
    int input_no{1}; //Counts number of iterations.
    double smaller{0},larger{0}; 

    while(cout<<"Enter a number : " && cin>>i)
    {   
        if(input_no==1){smaller=i;larger=i;}
        if(i==smaller||i==larger){}
        else if(i<smaller)
        {
            smaller=i;
        }
        else if(i>larger)
        {
            larger=i;
        }
        cout<<"So far Largest Num : "<<larger<<" and Smallest Num : "<<smaller
        <<"\n total number of input intil now: "<<input_no<<"\n ----- \n";
        input_no++;
    }
}
//[1] In first input the value of i by default goes to -
// a) var'Larger' if first input > 0 OR
// b) var'Smaller' if first input< 0
// Hence, when second input is given, it is either -
// a) >0 AND >larger OR 
// b) <0 AND <smaller
// In case (a) the previous(first) input automatically becomes the largest input so far (0 was just a placeholder)
// hence, the previous(first) input is the smallest so far.
// Same logic applies to case(b).

// PROBLEM TO FIX :-
// If user repeats value at first few inputs, then the above explained check fails to do, what it is supposed to do
// FIX IT!!!

// FIXED -
// The first input is now the value for both smallest and largest number, in first iteration. 
// No need to keep zero as placeholder because it is not one of the user_inputs.

// The Bug Occured only because - 
// if the second input is same as the first input, then the check that occurs at second input is useless.
// in this particular case it should occur at the third input.
// The root problem is describes below through an example 
// User Inputs '2' ---> Values become <smallest>=0 and <largest>=2
// User Inputs '5' ---> Values become <smallest>=0 and <larest>=5
// this is because <0> is also compared.
// we can ignore it since it is not one of the user inputs,
// hence, in first input we set both smallest and largest value equal to the first input.