/* FINDING an approximation for the max INT values storable in CPP using fibonnaci()*/

#include "./std_lib_facilities.h"

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
    vector<int> largest_approximations={};

    int n_elements=1000;
    //take input for starting values;
    int x; int y;
    while(cout<<"Please Enter first two values for your fibonnaci sq. : " && cin>>x>>y){
        cout<<"\n";
        fibonnaci(x,y,outp,n_elements);
        for(int i=0; i<outp.size(); ++i)
        {
            if(outp[i]<0)
            {largest_approximations.push_back(outp[i-1]);
            break;}
        }
        outp={}; //resets the vector for new fibonnaci sequence  
    }
    
    int avg_approx=0;

    for(int i:largest_approximations)
    {
        if(i>avg_approx){avg_approx=i;}//Takes the largest from all inputs yet. 
    }

    cout<<"Approximately the largest integer that can be accomodated in c++ int type is = "<<avg_approx<<"\n";
}