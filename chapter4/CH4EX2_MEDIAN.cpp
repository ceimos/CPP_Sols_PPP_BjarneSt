#include ".\std_lib_facilities.h"

int main()
{
    vector<double> temperatures;
    for(double tempes;cin>>tempes;)//Use a non double, non int input to break loop
    {
        temperatures.push_back(tempes);
    }
    cout<<"\n "<<temperatures.size()<<"\n";
    //Mean temperature
    double sum{0};
    for(double i:temperatures){sum+=i;}
    cout<<"Mean Temperature - "<<sum/temperatures.size()<<"\n";
    //Median temperature
    sort(temperatures);
    double median;
    int median_element;
    //if Even number of temps in the vector
    if(temperatures.size()%2==0)
    {
        median_element=(temperatures.size())/2; // This element + next element divided by 2. i.e. avg of mid two elems
        median=(temperatures[median_element-1]+temperatures[median_element])/2; //Index starts from zero so (-1) is necessary.
    }
    else //if Odd number of temps in the vecctor
    {
        median_element=(temperatures.size()+1)/2;
        median=temperatures[median_element-1];
    }
    cout<<"Median Temperature -"<<median<<"\n";
}