#include ".\std_lib_facilities.h"

vector<string> noun={"birds","fish","apples","ceimos"};
vector<string> verb={"fly","dance","eat","swim"};
vector<string> conj={"and","or","not"};

bool is_noun(string a)
{
    for(int i{0};i<noun.size();i++)
    {
        if(noun[i]==a)
        {
            return true;
        }
    }
    return false;
}

bool is_verb(string b)
{
    for(string i:verb)
    {
        if(i==b) return true;
    }
    return false;
}

bool is_conj(string c)
{
    for(string i:conj)
    {
        if(i==c) return true;
    }
    return false;
}

bool sentence()
{
    string a;
    cin>>a;
    if(!is_noun(a)){return false;}

    string b;
    cin>>b;
    if(!is_verb(b)){return false;}

    string c;
    cin>>c;
    if(c==".") return true;
    if(!is_conj(c))
    {
        return false;
    }
    return sentence();
}

int main()
{
    string sentence_input;
    while(cin)
    {
        bool b=sentence();
        if(b)
        {
            cout<<"ok"<<"\n";
        }
        else {cout<<"Not ok!"<<"\n";}
        cout<<"Try Again : \n";
    }
}