#include <iostream>
#include <vector>

using namespace std;

struct ISBN
{
    ISBN(int int1, int int2, int int3, char char1);
    int a; int b; int c; char d;
};

ISBN::ISBN(int int1, int int2, int int3, char char1){a{int1}, b{int2}, c{int3}, d{d}};

class Book
{
    private:
        string isbn;
        string title;
        string author;
        string copyright;
        bool checked_out{false};

    public:
        Book(string isbn, string title, string author, string copyright);
        string get_isbn() {return isbn;}
        const string get_title() {return title;}
        const string get_author() {return author;}
        const string get_copyright() {return copyright;}
        const bool get_checked_out() {return checked_out;}
        void check_out_in();
        int checkIsbn();
};

Book::Book(string isbn_, string title_, string author_, string copyright_) 
:isbn{isbn_}, title{title_}, author{author_}, copyright{copyright_}{}

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

int Book:: checkIsbn(){
    string x = get_isbn();

    if((x.length()==4)&&(x[0])&&(isdigit(x[1]))&&isdigit(x[2])){
        if(isalnum(x[3]))
            return 1;
    }
    else
        return 0;

}

void main()
{
    Book apple("12qa","apple","tree","adate");
    cout<<apple.checkIsbn()<<"\n";

    //while(true){
    //apple.check_out_in();}
}