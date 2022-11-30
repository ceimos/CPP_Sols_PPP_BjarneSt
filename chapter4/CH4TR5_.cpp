#include ".\std_lib_facilities.h"

int square(int x)
{
    int square_result{0};
    for(int i{0};i<x;++i){square_result+=x;}
    return square_result;
}

int main()
{
    int n{0};while(cin>>n)
    {
        cout<<square(n)<<"\t"; //Squaring through function.
        cout<<n*n<<"\n"; //Normal Squaring
    }
}