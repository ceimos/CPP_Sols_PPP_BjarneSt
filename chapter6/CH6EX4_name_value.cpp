// chapter 6 exercise 4 - rewriting chapter 4 ex 19
// adding name_value pair type.

#include ".\std_lib_facilities.h"

class name_value
{
    public:
        string name;
        double value;

        name_value(string n,double v): name(n),value(v){}
};

vector<name_value> store; //stores all the input name and value.

void main()
{
    string nme; double val;
    cout<<"type /X/ 0 to exit \n";

    while(cin>>nme>>val)
    {   
        if (nme=="/X/"){cout<<"exiting"<<"\n";break;}

        //duplicate value check 
        bool duplicate{false};
        for(int i=0;i<store.size();++i)
        {
            if(store[i].name==nme){cout<<"exiting - Duplicate names."<<"\n";duplicate=true;}
        }
        if (duplicate){break;}

        store.push_back(name_value(nme,val));
    }
    for(int i=0;i<store.size();++i)
    {
        cout<<"\n"<<store[i].name<<"\t"<<store[i].value<<"\n";
    }
}
