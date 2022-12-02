//ROCK PAPER SCISSOR
#include ".\std_lib_facilities.h"
vector<string> comp_choice{"rock","paper","scissor"};

//SCORE -
int comp_score{0};
int usr_score{0};
int draw{0};

int main()
{
    int seed{0};
    while(cout<<"Enter A seed (int) : "&&cin>>seed){
    if (seed<=100){}
    else
    {
        int diff; int ratio;
        diff=seed-100;
        ratio=diff*100/seed;
        seed=ratio; //Basically Keeps the sedd <=100 Needed for the next step
    }
    seed/=10; //gives a single digit number
    int index_com_choice=seed%3; //this gives us among 0, 1, or 2

    /*
    0 is rock
    1 is paper
    2 is scissor
    */

    //user input
    string usr_choice;
    cout<<"Choose among rock(r), paper(p), scissor(s) : ";
    cin>>usr_choice;

    if(usr_choice=="r"){usr_choice="rock";}
    else if(usr_choice=="p"){usr_choice="paper";}
    else if(usr_choice=="s"){usr_choice="scissor";}
    else{usr_choice="WrongInput";}

    if(usr_choice=="rock"&&index_com_choice==2){cout<<"You Win \n";usr_score+=1;}
    else if(usr_choice=="paper"&&index_com_choice==0){cout<<"You win! \n";usr_score+=1;}
    else if(usr_choice=="scissor"&&index_com_choice==1){cout<<"You win! \n";usr_score+=1;}
    else if(comp_choice[index_com_choice]==usr_choice){cout<<"Draw!! \n";draw+=1;}
    else if(usr_choice=="WrongInput"){cout<<usr_choice<<"\n";}
    else{cout<<"Computer Wins ! \n";comp_score+=1;}

    cout<<"\nYour Choice:"<<usr_choice<<"\n"
    <<"Computer Choice : "<<comp_choice[index_com_choice]<<"\n \n";

    cout<<"Scores - \nComputer Score : "<< comp_score<<"\n"
    <<"Player Score : "<<usr_score<<"\n"
    <<"Draws : "<<draw<<"\n\n";

}}