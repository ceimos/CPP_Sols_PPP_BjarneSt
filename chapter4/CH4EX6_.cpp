#include ".\std_lib_facilities.h"

int main()
{
    vector<string> num_spelled={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int usr_input_num;
    string usr_in_spell;
    int which_operation;

    while(cout<<"What to do : num-to-spell (0) OR spell-to-num(1) : " && cin>>which_operation)
    {
        if(which_operation==0)
        {
            while(cout<<"Enter A whole number(0,1,2, ... 9) to spell OR 'x' to exit : " && cin>>usr_input_num)
            {
                if(usr_input_num<10 && usr_input_num>=0)
                {
                cout<<"Your Number is spelled : "<<num_spelled[usr_input_num]<<"\n \n";
                }
                else{cout<<"Wrong Input! choose a whole number between zero(0) and nine(9) \n \n";}
            }
        }
        else if(which_operation==1)
        {
            while(cout<<"Spell a whole number(zero - nine) to get the number : " && cin>>usr_in_spell)
            {
                bool found_in_vect{false};
                for(int i{0};i<num_spelled.size();++i)
                {
                    if(num_spelled[i]==usr_in_spell)
                    {
                        cout<<usr_in_spell<<" is numerically : "<<i<<"\n \n";
                        found_in_vect=true;
                        break;
                    }
                }
                if(found_in_vect==false)
                {
                    cout<<"Wrong Input! choose a whole number between zero(0) and nine(9) \n \n";
                }
            }

        }
        else{cout << "try, again!";}
    }
}