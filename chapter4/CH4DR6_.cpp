#include ".\std_lib_facilities.h"

int main()
{
    double i;
    int input_no{1}; //Counts number of iterations.
    double smaller{0},larger{0}; 

    while(cout<<"Enter a number : " && cin>>i)
    {   
        if(i==smaller||i==larger){}
        else if(i<smaller)
        {
            if(input_no==2){larger=smaller;}//Only needed for the second time.[1] more in the comments below.
            smaller=i;
        }
        else if(i>larger)
        {
            if(input_no==2){smaller=larger;} //Only needed for the second time.[1] more in the comments below.
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