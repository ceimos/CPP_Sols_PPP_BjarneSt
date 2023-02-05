//MAX element of a vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

double maxv(const vector<double> v)
{
    double max=-999999999;

    for(double i:v)
    {
        if(i>max){max=i;}
    }
    return max;
}

void main()
{
    vector<double> test={1,2,3,9999999,5,698,7,8,10};
    cout<<maxv(test)<<"\n";
}