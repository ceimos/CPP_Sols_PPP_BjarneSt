//Takes Name-Number Pairs
//Stores in two different vectors, the name and value corresponds through a common index.
//Terminates on NoName 'o' and on duplicate Entry of name.
//
//Retrieve all the names for a given score. 
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

    //Print Name for given Number
    int num_retrieve;
    vector<int> index;
    cout<<"Enter the Score for which to retrive the name : ";
    cin>>num_retrieve;

    for(int i{0};i<scores.size();++i)
    {
        if(scores[i]==num_retrieve)
        {
            index.push_back(i);
        }
    }
    for(int i:index)
    {
        cout<<names[i]<<"\n";
    }
}