#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverse(vector<string>& v)
{
    for(int i=0;i<v.size()/2;++i)
    {
        swap(v[i],v[v.size()-1-i]);
    }
}   

int main()
{
    vector<string> input_v={"apple","balls","cats","dogs","elephants"};
    
    reverse(input_v);

    cout<<"reversed vector : {"; 
    for(string s:input_v)
    {
        cout<<s;
        if(s!=input_v[input_v.size()-1]){cout<<", ";}
    }
    cout<<"} \n\n";
}