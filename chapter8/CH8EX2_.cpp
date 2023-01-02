#include "./std_lib_facilities.h"

void print(vector<int>& v, const string& name)
{
    cout<<name<<": {";
    for(const int& a: v) //refer-b-const-value.
    {
        cout<<a;
        if(a!=v[(v.size()-1)]){cout<<",";} //Why didn't negative indexing work for this?
    }
    cout<<"} \n";
}

int main()
{
    vector<int> inp={1,2,3,4,5,6,7};
    print(inp, "This Vector ");
}