//Money Counter.
#include ".\std_lib_facilities.h"

int main()
{
    int pennies,nickels,dimes,quarters,halfD,oneD;
    double total_cents;
    double total_dollars;

    //INPUTS -
    cout<<"Enter How many Coins you have : ";
    cout<<"\n Pennies : "; cin>>pennies;
    cout<<"\n nickels : "; cin>>nickels;
    cout<<"\n dimes : "; cin>>dimes;
    cout<<"\n quarters : "; cin>>quarters;
    cout<<"\n half Dollar : "; cin>>halfD;
    cout<<"\n One Dollar : "; cin>>oneD;

    //CALCULATIONS -
    total_cents=(pennies*1)+(nickels*5)+(dimes*10)+(quarters*25)+(halfD*50)+(oneD*100);
    total_dollars=total_cents/100;
    
    //CONFIRMATION PRINT - DEPRECATED
    //cout<<"You have :- \n"
    //<<pennies<<" pennies \n"
    //<<nickels<<" nickels \n"
    //<<dimes<<" dimes \n"
    //<<quarters<<" quarters \n"
    //<<halfD<<" half Dollars \n"
    //<<oneD<<" one Dollars \n";

    //GRAMMATICALLY CORRECT CONFIRMATION PRINT STATEMENTS - 
    if(pennies!=1){cout<<pennies<<" pennies \n";}
    else{cout<<pennies<<" penny \n";}

    if(nickels!=1){cout<<nickels<<" nickels \n";}
    else{cout<<nickels<<" nickel \n";}

    if(dimes!=1){cout<<dimes<<" dimes \n";}
    else{cout<<dimes<<" dime \n";}

    if(quarters!=1){cout<<quarters<<" quarters \n";}
    else{cout<<quarters<<" quarter \n";}

    if(halfD!=1){cout<<halfD<<" half Dollars \n";}
    else{cout<<halfD<<" half Dollar coin \n";}

    if(oneD!=1){cout<<oneD<<" one Dollars \n";}
    else{cout<<oneD<<" one Dollar coin \n";}


    //TOTAL PRINT - 
    cout<<" Total == "<<total_cents<<" cents"
    <<"\n OR "<< total_dollars << " Dollars \n";   
}