#include ".\std_lib_facilities.h"

int main()
{
    double i{0};
    string unit;
    double last_input{0};
    constexpr double m_cm{100};
    constexpr double in_cm{2.54};
    constexpr double ft_in{12.0};
    double input_sum{0};
    vector<double> all_measurements;

    //for smallest and largest comparison - 
    double smaller{0},larger{0}; 

    //count no. of iterations
    int input_no{1};

    while(cout<<"Enter a measurement with unit (allowed:m,cm,in,ft): " && cin>>i>>unit)
    {
        cout<<"input is : "<<i<<"   "<<unit<<"\n";

        if(unit!="m" && unit!="cm" && unit!="in" && unit!="ft")
        {
            unit="none";
            i=0;
            cout<<"wrong Input, try Again! \n";
        }

        else
        {
            //convert to m
            if(unit=="m"){}
            else if(unit=="cm"){i/=m_cm;}
            else if(unit=="in"){i*=in_cm;i/=m_cm;}
            else if(unit=="ft"){i*=ft_in;i*=in_cm;i/=m_cm;}

            //add to the vector
            all_measurements.push_back(i);

            //add to sum
            input_sum+=i;
            cout<<"The Sum of inputs so far : "<<input_sum<<" m \n";

            //Smallet-so-far and Largest-so-far -
            if(input_no==1){larger=i;smaller=i;}
            if(i==smaller||i==larger){}
            else if(i<smaller)
            {
                smaller=i;
            }
            else if(i>larger)
            {
                larger=i;
            }
            cout<<"So far Largest Measurement : "<<larger<<" meter and Smallest Measurement : "<<smaller<<" meter \n"
            <<"total number of input intil now: "<<input_no<<"\n";
        }
        input_no+=1;

        //Print the vector that has the data.
        sort(all_measurements);
        cout<<"all the inputs : ";
        for(int i{0};i<all_measurements.size();++i)
        {
            if(i!=all_measurements.size()-1){cout<<all_measurements[i]<<",";} //adds comma until the last value.
            else{cout<<all_measurements[i]<<" \n";}
        }
        cout<<"\n \n";
    }
}