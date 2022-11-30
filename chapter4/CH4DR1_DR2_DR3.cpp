#include ".\std_lib_facilities.h"

int main()
{
    int i,z;
    int smaller;
    int larger;
    while(cin>>i>>z)
    {
        cout<<"inputs were:"<< i << "\t and \t " <<z << "\n"; //Drill 1

        if(i<z){smaller=i;larger=z;} //Drill 2
        else{smaller=z;larger=i;} 
        cout<<"smaller number:"<<smaller<<"  and   larger number :"<<larger << "\n";

        //Drill 3
        if(i<z){smaller=i;larger=z;cout<<"smaller number:"<<smaller<<"  and   larger number :"<<larger << "\n";}
        else if(i==z){cout<<"Both numbers are equal and equal to "<<i<<" \n";}
        else{smaller=z;larger=i;cout<<"smaller number:"<<smaller<<"  and   larger number :"<<larger << "\n";}

        //Alternative without a extra variables
        if(i<z){cout<<"smaller number:"<<i<<"  and   larger number :"<<z<< "\n"; }
        else{cout<<"smaller number:"<<z<<"  and   larger number :"<<i<< "\n";}

        //Alternativ2 - just three variables.
        if(i<z){smaller=i;i=z;}
        else{smaller=z;}
        cout<<"smaller number:"<<smaller<<"  and   larger number :"<<i<< "\n";
    }
}