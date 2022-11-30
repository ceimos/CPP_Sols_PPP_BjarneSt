#include ".\std_lib_facilities.h"

int main()
{
    double i,z;
    double smaller,larger;
    double diff_ratio; //how small is the smaller number than the bigger number    
    while(cin>>i>>z)
    {   
        if(i==z){cout<<"Both numbers are same. \n";}
        else if(i<z){smaller=i;larger=z;}
        else{smaller=z;larger=1;}

        if(i!=z)
        {
            diff_ratio=(larger-smaller)/larger;
            cout<<"Larger Number : "<<larger<<" Smaller Number : "<<smaller<<" \n";
            if(diff_ratio<0.01){cout<<"However Both numbers are similar. ";}
        }
    }
}