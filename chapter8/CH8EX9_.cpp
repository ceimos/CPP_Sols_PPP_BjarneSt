#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_double_vector(const vector<double>& v, string vector_type) //prints vector of type double
{
    cout<<vector_type<<" : {";
    for(double i:v)
    {
        cout<<i;
        if(i!=v[v.size()-1]){cout<<", ";}
    }
    cout <<"} \n\n";
}

void set_given_values(vector<double>& prices, vector<double>& weights)
{
    for(int i=1; i<11; ++i){prices.push_back(i+30); weights.push_back(i*25);}
    print_double_vector(prices, "Given Prices ");
    print_double_vector(weights,"Give weights" );
}

int get_index(const vector<double>& v, double i)
{
    auto t=find(v.begin(),v.end(),i);

    if(t!=v.end()){
        int index = t-v.begin();
        return index;
    }
    else{return -1;}
}

void main()
{
    vector<double> price; //given
    vector<double> weight; //given

    set_given_values(price,weight);
    
    cout<<"Values in Order : { ";

    for(int i=0;i<price.size();++i)
    {
        double value=price[i]*weight[i];
        cout<<value;
        if(i!=price.size()-1){cout<<",";}
    } 
 
    cout<<"}\n";
}