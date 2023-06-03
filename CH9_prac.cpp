#include <iostream>
#include <vector>

using namespace std;

void fib(const int& x, const int& y, vector<int>& v, const int& n)
{ 
    v.push_back(x);v.push_back(y);
    for(int i {0}; i<=n-2; ++i)
    {
        int next_element = v[i]+v[i+1];
        v.push_back(next_element);
    }
}

void print_vector(const vector<int>& v)
{
    for(int i:v){cout<<i<<"\n";}
}

int main()
{
    vector<int> vec;
    fib(1,2,vec,5);
    print_vector(vec);

    return 0;
}


