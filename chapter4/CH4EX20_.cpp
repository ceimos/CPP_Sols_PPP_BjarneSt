//Takes Name-Number Pairs
//Stores in two different vectors, the name and value corresponds through a common index.
//Terminates on NoName 'o' and on duplicate Entry of name.
//Prints Name-Number Pair
//
//Retrieves the score for a given name.

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
    string name_retrieve;
    vector<int> index;
    cout<<"Enter the Name for which to retrive the Score : ";
    cin>>name_retrieve;

    for(int i{0};i<scores.size();++i)
    {
        if(names[i]==name_retrieve)
        {
            index.push_back(i); //Doesn't need to be a vector because there are no duplicate names.
        }
    }
    for(int i:index)
    {
        cout<<scores[i]<<"\n";
    }
}