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
        const vector<string> return_name(){return names;}
        const vector<int> return_age(){return ages;}
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

void Name_Pair::read_ages() //works only if the user implements read_ages() after read_names. FIX THIS!!!
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

bool operator==(Name_Pair& pair1,Name_Pair& pair2)
{
    // if all (pair1.name,pair1.age) exists in pair2, and pair1.size()==pair2.size() is True.

    pair1.sort();pair2.sort(); //if the elements are same they will be correspond in sorted pairs, else the sorted pair are not same.

    const vector<string>& names_1 = pair1.return_name();
    const vector<string>& names_2 = pair2.return_name();

    const vector<int>& ages_1 = pair1.return_age();
    const vector<int>& ages_2 = pair2.return_age();

    if(names_1.size()==names_2.size()) //no point in comparing if number of elements are not equal.
    {
        for(int i {0}; i<names_1.size(); ++i)
        {
            if(names_1[i]!=names_2[i]){return false;}
        }
        //if all names match then compare ages
        for(int i {0}; i<ages_1.size();++i)
        {
            if(ages_1[i]!=ages_2[i]){return false;}
        }
        return true;
    }
    else { return false;}
}

bool operator!=(Name_Pair& pair1,Name_Pair& pair2) // True if pairs are not equal.
{
    // if all (pair1.name,pair1.age) exists in pair2, and pair1.size()==pair2.size() is True.

    pair1.sort();pair2.sort(); //if the elements are same they will be correspond in sorted pairs, else the sorted pair are not same.

    const vector<string>& names_1 = pair1.return_name();
    const vector<string>& names_2 = pair2.return_name();

    const vector<int>& ages_1 = pair1.return_age();
    const vector<int>& ages_2 = pair2.return_age();

    if(names_1.size()==names_2.size()) //no point in comparing if number of elements are not equal.
    {
        for(int i {0}; i<names_1.size(); ++i)
        {
            if(names_1[i]!=names_2[i]){return true;}
        }
        //if all names match then compare ages
        for(int i {0}; i<ages_1.size();++i)
        {
            if(ages_1[i]!=ages_2[i]){return true;}
        }
        return false;
    }
    else { return true;}
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

    cout<<"\n \n";

    Name_Pair test1; Name_Pair test2;

    test1.read_names();
    test1.read_ages();
    test2.read_names();
    test2.read_ages(); //FIX the implementation problem.

    if(test1==test2){cout<<"the pairs are equal";}
    else{cout<<"the pairs are not equal";}

    return 0;
}