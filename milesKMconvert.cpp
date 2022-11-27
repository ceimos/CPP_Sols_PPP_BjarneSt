//Chapter3 Exercise 2.
//Convert Miles to KM.
#include ".\std_lib_facilities.h"

int main(){
    double mile {0};
    double km {0};
    string breaker=string(10,'--');
        while(cout<<"Enter Miles - " && cin>>mile){
        km=mile*1.608;
        if(mile<0){
            km*=-1; mile*=-1;
        }
        if(mile!=1){
            //for Plural Miles.
            cout << "\n " << mile << " miles is " << km << " KM. \n \n"; 
        }
        else{
            //for Singular miles.
            cout << "\n " << mile << " mile is"<< km << " KM. \n \n";
        }
        cout<<breaker<<"\n";
    }
}