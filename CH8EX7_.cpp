#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<string>& v, string vector_type) //vector_type - original vector or reversed vector.
{
    cout<<vector_type<<" : {";
    for(string i:v)
    {
        cout<<i;
        if(i!=v[v.size()-1]){cout<<", ";}
    }
    cout <<"} \n\n";
}

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

int find_index(const vector<string>& v, string i)
{
    auto k=find(v.begin(),v.end(),i);

    if (k != v.end())
    {
        int index = k-v.begin();
        return index;
    }

    else
    {
        return -1;
    }
}

//printing name-age pair
void print_pair(const vector<double>& ages, const vector<string>& names)
{
    cout<<"The (name,age) pairs are :\n\t {\n\t\t";
    int index=0;
    for(string i:names)
    {
        index=find_index(names,i); //find index of i in names vector
        double age=ages[index];

        cout<<"("<<i<<","<<age<<")";

        if(i!=names[names.size()-1])
        {
            cout<<",";
        }
    }
    cout<<"\n\t } \n";
}

int main()
{
    vector<string> names;
    vector<double> ages;

    string name=" ";
    double age=0;

    while(cin>>name)
    {
        if(name=="!quit"){break;}
        names.push_back(name);
        
    }

    print_vector(names, "You have Entered");

    for(string i:names)
    {
        cout<<"Enter Age for "<<i<<" : ";
        cin>>age;
        if(!cin){cout<<"ERROR! Invalid Entry"; break;}
        ages.push_back(age);
    }
    
    print_double_vector(ages,"The ages in order ");
    print_pair(ages,names);

    //sorting the names, then printing CORRECT pairs of names and age.
    //CAN't use the print_pair()
    vector<string> names_copied=names;
    sort(names.begin(),names.end());

    cout<<"The sorted (name,age) pairs are :\n\t {\n\t\t";

    for(string i:names)
    {
        int index=find_index(names_copied,i);
        double age=ages[index];

        cout<<"("<<i<<","<<age<<")";

        if(i!=names[names.size()-1])
        {
            cout<<",";
        }
    }
    cout<<"\n\t } \n";
}