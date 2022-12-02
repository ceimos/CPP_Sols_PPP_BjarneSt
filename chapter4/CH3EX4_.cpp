#include ".\std_lib_facilities.h"

int main()
{
    char high_low;
    int min{1}; int max{100}; int mid{max/2};

    cout<<"I will guess the number you thinking about - 'n";
    cout<<"\nIs your number (l)ower than "<<mid<<" or (h)igher ? : ";
    cin<<high_low;
    if(high_low=='h'||high_low=='H')
    {
        min=mid;
        mid=max/2;
    }
    else(high_low='l'||high_low='L')
    {
        max=mid;
        mid=max/2;
    }
}