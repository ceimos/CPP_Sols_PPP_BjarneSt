#include <iostream>
#include <vector>

using namespace std;

//ISBN Struct

struct ISBN
{
    ISBN(int int1, int int2, int int3, char char1);
    int a; int b; int c; char d;
};

ISBN::ISBN(int int1, int int2, int int3, char char1) :a{int1}, b{int2}, c{int3}, d{d} {};

class Book
{
    private:
        ISBN isbn;
        string title;
        string author;
        string copyright;
        bool checked_out{false};

    public:
        Book(ISBN isbn, string title, string author, string copyright);
        ISBN get_isbn() {return isbn;} //define cout<<ISBN;
        const string get_title() {return title;}
        const string get_author() {return author;}
        const string get_copyright() {return copyright;}
        const bool get_checked_out() {return checked_out;}
        void check_out_in();
        int check_isbn();
};

Book::Book(ISBN isbn_, string title_, string author_, string copyright_) 
:isbn{isbn_}, title{title_}, author{author_}, copyright{copyright_}{};

void Book::check_out_in()
{
    if(checked_out==false) 
    {
        string answer;
        cout<<"Do you want to check out this book  (y/n) ?";
        cin>>answer;

        if(answer=="y"||answer=="y")
        {
            checked_out=true;
            cout<<get_title()<<" is now checked out. \n";
        }
        else if (answer=="n"||answer=="N")
        {
            cout<<"\n Book is available and not checked out already! \n";
        }
        else { cout << "\n wrong input, try again \n "; check_out_in();}
    }
    
    else
    {
        string answer;
        cout<<"Do you want to check in (return) \" "<<get_title()<<" \" (y/n) ?";
        cin>>answer;
        if(answer=="y"||answer=="y")
        {
            checked_out=false;
            cout<<get_title()<<" is now returned. \n";
        }
        else if (answer=="n"||answer=="N")
        {
            cout<<"\n Book is not available to be checked out! \n";
        }
        else { cout << "\n wrong input, try again \n "; check_out_in();}
    }
}

int Book::check_isbn()
{
    ISBN isbn=get_isbn();
    
    char a = static_cast<char>(isbn.a + '0'); //type casting
    char b = static_cast<char>(isbn.b + '0');
    char c = static_cast<char>(isbn.c + '0'); 
    
    if(isdigit(a) && isdigit(b) && isdigit(c) && isalnum(isbn.d)){return 1;}
    return 0;
}

void main()
{
    try{
        Book test1(ISBN{1,2,3,'c'},"apple","tree","adate");
 
        if(test1.check_isbn()==0){cout<<"wrong ISBN! \n";}
        else if (test1.check_isbn()==1){cout<<"Correct ISBN \n";}
    }
    catch(...)
    {
        cout<<"Invalid Values for a book object. \n";
    }

    //while(true){
    //apple.check_out_in();}
}