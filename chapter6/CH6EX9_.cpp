#include ".\std_lib_facilities.h"

int main()
{
    double result=0;
    vector<char> output;
    vector<string> place_value={" thousands"," hundreds"," tens"," ones"};

    
    cout<<"Enter '~' to exit the input loop and show the result. \n"
    <<"Enter a number (not multiple) : ";

    while(cin)
    {
        char ch;
        cin>>ch;

        if(ch==' '){ch='0';}
        if(!cin){cout<<"Error : no input try again! \n"; break;}
        else if(ch=='~'){cout<<"exiting input prompt...\n"; break;}

        int digit=ch-'0'; //the current digit in integer type.
        result*=10;//increases the place value for the last digit.
        result+=digit;//This is int type for the given input

        output.push_back(ch);//stores the input values in a array, place value is decided based on index.

    }

    int index_increment=place_value.size()-output.size();
    //depending on number of digits, the index for place_value vector should start at 0 or 1 or 2 or 3.
    /*if(output.size()==1){index_increment=3;}
    else if(output.size()==2){index_increment=2;}
    else if(output.size()==3){index_increment=1;}*/

    string output_string{" "}; //Stores the string to output
    for(int i=0;i<output.size();++i)
    {
        output_string+=output[i]+place_value[i+index_increment]+", ";
    }

    cout<<"The number is ("<<result<<") : "<<output_string<<"\n";
}