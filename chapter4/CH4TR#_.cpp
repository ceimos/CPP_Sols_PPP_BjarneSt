#include ".\std_lib_facilities.h"

int main()
{
    double yen{0};
    double euro{0};
    double pound{0};
    double yuan{0};
    double kroner{0};
    constexpr double conv_yen{0.0073}; //conversion rates 1 yen=0.0073 dollars
    constexpr double conv_euro{1.04};
    constexpr double conv_pound{1.21};
    constexpr double conv_yuan{0.14};
    constexpr double conv_kroner{0.10};
    char curr_to_conv;
    cout<<"Enter Currency to convert - Y for yen, E for euro, P for pound, K for kroner, U for Yuan : ";
    cin>>curr_to_conv;
    if(curr_to_conv=='Y'||curr_to_conv=='y')
    {
        cout<<"\n Enter Amount in Yen : ";cin>>yen;
        cout<<"\n"<<yen<<"Yen is "<<yen*conv_yen<<"Dollars \n";
    }
    else if(curr_to_conv=='E'||curr_to_conv=='e')
    {
        cout<<"\n Enter Amount in Euro : ";cin>>euro;
        cout<<"\n"<<euro<<"Euro is "<<euro*conv_euro<<"Dollars \n";
    }
    else if(curr_to_conv=='P'||curr_to_conv=='p')
    {
        cout<<"\n Enter Amount in Pound : ";cin>>pound;
        cout<<"\n"<<pound<<"Pound is "<<pound*conv_pound<<"Dollars \n";
    }
    //else{cout<<"\n Sorry Wrong Input, Try Again! \n";}
    //Deprecated else Statement above(line 33) in favour of switch-default statement(line:50)
    
    //Trying Switch Cases Below -
    switch(curr_to_conv)
    {
        case 'k': case 'K': 
        cout<<"\n Enter Amount in Kroner : "; 
        cin>>kroner;
        cout<<"\n"<<kroner<<"Kroner is "<<kroner*conv_kroner<<"Dollars \n";
        break;
        //yu for Yuan
        case 'u': case 'U':
        cout<<"\n Enter Amount in Yuan : "; 
        cin>>yuan;
        cout<<"\n"<<yuan<<"Yuan is "<<yuan*conv_yuan<<"Dollars \n";
        break;
        default : cout<<"\n Sorry Wrong Input, Try Again! \n";
    }
}