#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Name_Pair
{
    private:
        vector<string> names;
        vector<int> ages;

    public:
        void read_names();
        void read_ages();
        void print();
        void sort();
        vector<string> return_name(){return names;}
        vector<int> return_age(){return ages;}
};

void Name_Pair::read_names()
{
    cout<<"Enter Names (enter q when done.): ";
    while(cin)
    {
        string name;
        cin>>name;
        if(name=="quit"||name=="q"){break;}
        names.push_back(name);
    }
}

void Name_Pair::read_ages()
{
    for(int i {0}; i<names.size();++i)
    {
        int age{0};
        cout<<"Enter Age for "<<names[i]<<" : ";
        cin>>age;
        ages.push_back(age);
    }

}

void Name_Pair::print()
{
    for(int i {0}; i<names.size();++i)
    {
        cout<<"("<<names[i]<<","<<ages[i]<<")"<<"\n";
    }
}

void Name_Pair::sort()
{
    vector<string> names_copy=names;
    vector<int> ages_sorted;

    std::sort(names.begin(),names.end()); //since namespace scope changed, 'std' is explicitly mentioned here.

    for(string n:names)
    {
        auto index = find(names_copy.begin(),names_copy.end(),n);
        int i= index-names_copy.begin();
        ages_sorted.push_back(ages[i]);
    }
    ages=ages_sorted;
}

void operator<<(ostream& COUT, Name_Pair& np) //solution for Exercise 3 - overload '<<' operator (globally).
{
    const vector<string>& names = np.return_name();
    const vector<int>& ages = np.return_age();

    for(int i {0}; i<names.size();++i)
    {
        cout<<"("<<names[i]<<","<<ages[i]<<")"<<"\n";
    }
}

int main()
{
    Name_Pair test_pair;

    test_pair.read_names();

    cout<<"\n";

    test_pair.read_ages();

    cout<<"Before Sort  - \n\n";

    //test_pair.print(); replaced with << overloaded operator
    cout << test_pair;
    
    test_pair.sort();

    cout<<"After Sort  - \n\n";

    test_pair.print();

    cout<<"\n";

    return 0;
}