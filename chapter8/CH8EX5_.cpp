/* Reversing order of elements in a given vector.
Logic Seems to be right but, it is not working properly. Even Bjarne's Code is not working properly.*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse_vec(const vector<int>& v)
{
    vector<int> reversed={};
    for(int i=v.size()-1;i>=0;--i)
    {
        reversed.push_back(v[i]);
    }
    return reversed;
}

vector<int> reverse_swap(vector<int>& v)
{
    int iteration_num=0; //how many elements starting from 0 has the loop sent to right position.
    while(iteration_num<v.size( ))
    {
        for(int i=0;i<v.size()-iteration_num;++i) //leaves the completed elements.
        {
            swap(v[i],v[i+1]);
        }
        iteration_num+=1;
    }
    return v;
}

vector<int> reverse_corr_swap(vector<int>& v)
{
    for(int i=0; i<v.size()/2;++i)
    {
        swap(v[i],v[v.size()-1-i]);
    }

    return v;
}

void reverse2(vector<int>& v)
	// reverse by swapping "corresponding" elements
{
	for(int i = 0; i<v.size()/2; ++i)
		swap(v[i],v[v.size()-1-i]);	// first swaps with last, etc.
}

int main()
{
    vector<int> test={1,2,3,4,5,6,7,8,9};

    vector<int> result=reverse_vec(test);
    vector<int> result_swap=reverse_swap(test);
    vector<int> result_swap_corr=reverse_corr_swap(test);

    reverse2(test);

    cout<<"{";
    for(int i:result)
    {
        cout<<i;
        if(i!=test[0]){cout<<",";}
    }
    cout<<"} \n \n";
}