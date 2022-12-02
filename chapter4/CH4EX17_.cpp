// FINDS MIN MAX AND MODE OF A SEQ of STRINGS
#include ".\std_lib_facilities.h"

vector<string> seq;

int main()
{
    cout<<"Enter a sequence of strings : ";
    string input;
    while(cin>>input){seq.push_back(input);}

    sort(seq);
    
    string min=seq[0];
    string max=seq[seq.size()-1]; 
    string mode{""};
    string mode_2(" "); //for multiple modes

    int highest_occ{0};
    
    for(string i:seq)
    {
        if(i==mode)//seq is sorted so shouldn't check the repeated words , again.
        {
            continue;
        }
        int no_of_occ{0};
        for(string z:seq)
        {
            if(i==z){no_of_occ+=1;}
            if(no_of_occ>1 && i!=z){break;}
        }
        
        if(no_of_occ==highest_occ && mode!=i) //In case two strings are modes
        {
            mode_2+=i;
        }
        if(no_of_occ>highest_occ)
        {
            highest_occ=no_of_occ;
            mode=i;
        }
    }
    cout<<"Mode is - "<< mode<<"and"<<mode_2<<"\n"
    <<"Total Number of Occurences - "<<highest_occ<<"\n";
}