//Find mode from given set of numbers
#include ".\std_lib_facilities.h"

int main()
{
    vector<double> seq;
    double input;
    double mode;

    cout<<"Enter some Numbers : ";
    while(cin>>input)
    {
        seq.push_back(input);
    }
    sort(seq);
    int greatest_num_of_occ{0}; //To store highest amount of occurence.
    for(double i:seq)
    {
        int num_of_occ{0}; //To store num of occ of this particular number (i)
        for(double z:seq)
        {
            if(i==z){num_of_occ+=1;}
            if(num_of_occ>1 && i!=z){break;} //seq is sorted, so this loop stops after all the occurences have been matched.
        }
        if(num_of_occ>greatest_num_of_occ)
        {
            greatest_num_of_occ=num_of_occ;
            mode=i;
        }
    }
    cout<<"Mode is - "<< mode<<"\n"
    <<"Total Number of Occurences - "<<greatest_num_of_occ<<"\n";
}