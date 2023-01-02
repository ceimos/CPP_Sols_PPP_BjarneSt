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

void fibonnaci(const int& x, const int& y, vector<int>& v, const int& n) //giving v as reference modifies the original vector. 
{
    v.push_back(x); v.push_back(y);
    for(int i=2; i<n; ++i) //Starts at 3 as v[0]=x, and v[1]=y
    {
        int put_back=v[i-1]+v[i-2];
        v.push_back(put_back);
    }
}

int main()
{
    vector<int> outp={};
    int n_elements=10;
    //take input for starting values
    cout<<"Please Enter first two values for your fibonnaci sq. : ";
    int x; int y;
    while(cin>>x>>y){
        cout<<"\n";
        fibonnaci(x,y,outp,n_elements);
        print(outp, "Fibonnaci ");
        outp={}; //resets the vector for new fibonnaci sequence  
    }
}