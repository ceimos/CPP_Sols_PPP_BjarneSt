#include ".\std_lib_facilities.h"

int main()
{
    vector<string> disliked={"apple","cat","dog","eleven"};
    vector<string> usr_inpt;
    bool exists{false};
    for(string words; cin>>words;){usr_inpt.push_back(words);}

    for(string z:usr_inpt){
        for(string i:disliked){
            if(z==i){exists=true;break;} //if it finds the match, it will not compare with rest of the words in disliked
        }
        if(exists==true){cout<<"**** ";}
        else{cout<<z<<" ";}
        exists=false;
    }
    cout<<"\n";
}

//This will also work without the break; in line 12, but this is more effiecient.
//simply because, furthur iteration is cancelled once a match is found. 