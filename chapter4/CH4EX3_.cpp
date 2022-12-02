#include ".\std_lib_facilities.h"

int main()
{
    double dist;
    vector<double> distances;
    double smallest;
    double largest;
    double mean;
    double sum{0};
    
    while(cout<<"Enter Distance : " && cin>>dist)
    {
        cout<<"\nInput: "<<dist<<"\n";
        distances.push_back(dist);
        sum+=dist;
    }
    sort(distances); //sorts in ascending order
    smallest=distances[0];
    largest=distances[distances.size()-1];//the last elements
    //Find mean of distances -
    mean=sum/distances.size();

    cout<<"\nSmallest distance : "<<smallest
    <<"\nLargest Distance : "<<largest
    <<"\nMean Distance : "<< mean
    <<"\nTotal Distance : "<<sum <<"\n \n";
}