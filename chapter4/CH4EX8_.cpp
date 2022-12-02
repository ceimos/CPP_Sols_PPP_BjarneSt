#include ".\std_lib_facilities.h"

int atleast_1000_rice_square{0};
int atleast_million_rice_square{0};
int atleast_billion_rice_square{0};

bool atleast_done_1000{false}; //tracks if the atleast value is printed.
bool atleast_done_million=false;
bool atleast_done_billion=false;

int main()
{
    unsigned _int64 rice_num{1}; //int 8 bytes. Upto twenty digits accepted but only 0 to 18,446,744,073,709,551,615.
    //the 2^64 suquare wont be printed, beacause it exceeds the value.

    for(int square_no{1};square_no<=64;++square_no)
    {
        rice_num*=2; //double for each square
        cout<<"Square Number : "<<square_no<<"\n"
        <<"Number of Rice : "<<rice_num<<"\n \n";

        //atleast 1000 rice
        if(rice_num>=1000 && atleast_done_1000==false)
        {
            cout<<"For Atleast 1000 rice grains ---> \n"
            <<"Number of rice : "<<rice_num<<"\n"
            <<"Number of square : "<<square_no<<"\n \n";
            atleast_done_1000=true;
            atleast_1000_rice_square=square_no;
        }

        //atleast million rice
        if(rice_num>=1000000 && atleast_done_million==false)
        {
            cout<<"For Atleast million rice grains ---> \n"
            <<"Number of rice : "<<rice_num<<"\n"
            <<"Number of square : "<<square_no<<"\n \n";
            atleast_done_million=true;
            atleast_million_rice_square=square_no;
        }

        //atleast billion rice
        if(rice_num>=1000000000 && atleast_done_billion==false)
        {
            cout<<"For Atleast 1000 rice grains ---> \n"
            <<"Number of rice : "<<rice_num<<"\n"
            <<"Number of square : "<<square_no<<"\n \n";
            atleast_done_billion=true;
            atleast_billion_rice_square=square_no;
        }
    }
    cout<<"\n --------------- FINAL RESULT --------------- \n"
    <<"For atleast 1000 rice, no. of square neede == "<< atleast_1000_rice_square<<"\n"
    <<"For atleast million rice, no. of square neede == "<< atleast_million_rice_square<<"\n"
    <<"For atleast billion rice, no. of square neede == "<<atleast_billion_rice_square<<"\n";
}