//Takes Name-Number Pairs
//Stores in two different vectors, the name and value corresponds through a common index.
//Terminates on NoName 'o' and on duplicate Entry of name.
//Prints Name-Number Pair

#include ".\std_lib_facilities.h"

int main()
{
    vector<string> names;
    vector<int> scores;

    string name; int score;

    cout<<"To terminate enter \"NoName 0\" \n";
    
    while(cout<<"Enter Name-Value Pair with Space Between them : " && cin>>name>>score)
    {
        if(name=="NoName"&&score==0){cout<<"terminating... \n";break;}

        bool is_repeated=false;
        for(string n:names)
        {
            if(n==name){cout<<"TERMINATING, Duplicate Entries."<<"\n"; is_repeated=true;}
            else{is_repeated=false;}
        }
        if(is_repeated==false)
        {
            names.push_back(name);
            scores.push_back(score);
        }
        else{break;}
        
    }
    //Print Name Number Pair
    for(int i{0};i<names.size();++i)
    {
        cout<<names[i]<<"    "<<scores[i]<<" \n";
    }
}