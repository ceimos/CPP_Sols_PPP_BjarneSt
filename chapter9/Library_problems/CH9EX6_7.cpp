#include <iostream>
#include <vector>

using namespace std;

struct ISBN
{
    ISBN(int int1, int int2, int int3, char char1) :a{int1}, b{int2}, c{int3}, d{char1} {};
    int a; int b; int c; char d;
};

enum class Genre{Fiction, Biography, Periodical, Children, NonFiction, undefined};


class Book
{
    private:
        ISBN isbn;
        string title;
        string author;
        string copyright;
        Genre genre{Genre::undefined};
        bool checked_out{false};

    public:
        Book(ISBN isbn_, string title_, string author_, string copyright_, Genre genre_);
        ISBN get_isbn() {return isbn;}
        const string get_title() {return title;}
        const string get_author() {return author;}
        const string get_copyright() {return copyright;}
        const Genre get_genre(){return genre;}
        const bool is_available() {return checked_out;}
        void check_out_in();
        int check_isbn();
};

Book::Book(ISBN isbn_, string title_, string author_, string copyright_, Genre genre_) 
:isbn{isbn_}, title{title_}, author{author_}, copyright{copyright_}, genre{genre_}{};

ostream& operator<<(ostream& COUT,const ISBN& isbn) //ostream return type so that multiple isbn can be printed at a time. cout<<isbn1<<isbn2;
{
    COUT<<isbn.a<<isbn.b<<isbn.c<<isbn.d;
    return COUT;
}

ostream& operator<<(ostream& COUT,const Genre& genre_)
{
    vector<string> genre_strings{"Fiction", "Biography", "Periodical", "Children", "NonFiction", "undefined"};

    COUT<<genre_strings[int(genre_)];
    return COUT;
}

bool operator==(const ISBN& isbn1, const ISBN& isbn2) //for isbn comparison.
{
    return isbn1.a==isbn2.a && isbn1.b==isbn2.b && isbn1.c==isbn2.c && isbn1.d==isbn2.d;
}

bool operator==(Book& book1, Book& book2)
{
    return book1.get_isbn()==book2.get_isbn();
}

bool operator!=(Book& book1, Book&book2)
{
    return !(book1.get_isbn()==book2.get_isbn());
}

ostream& operator<<(ostream& COUT, Book& book)
{
    COUT<<"ISBN : "<< book.get_isbn()
    <<"\nAuthor : "<< book.get_author()
    <<"\nTitle : "<< book.get_title()
    <<"\nGenre : "<< book.get_genre()<<"\n";
    return COUT;
}

void Book::check_out_in()
{
    if(is_available()==false) 
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
    
    char a = static_cast<char>(isbn.a + '0'); //type casting; isdigit() works only for characters 
    char b = static_cast<char>(isbn.b + '0');
    char c = static_cast<char>(isbn.c + '0'); 
    
    if(isdigit(a) && isdigit(b) && isdigit(c) && isalnum(isbn.d)){return 1;} // isdigit() works only for characters.
    return 0;
}

void main()
{
    try{
        Book test1(ISBN{1,2,3,'c'},"apple","tree","adate",Genre::Biography);
        Book test2(ISBN{1,2,3,'2'}, "apple2", "tree", "mango",Genre::Children);
        Book test3(ISBN{1,5,3,'g'}, "aple", "treed", "mango",Genre::undefined);
 
        if(test1.check_isbn()==0){cout<<"wrong ISBN! \n";}
        else if (test1.check_isbn()==1){cout<<"Correct ISBN \n";}

        string equality = (test1==test3) ? "equal \n" : "not equal \n";
        string non_equality = (test1!=test3) ? "not equal \n" : "equal \n"; 
        cout << equality;
        cout << non_equality;
        cout << "\n" << test1 <<"\n"<< test2 << "\n";
    }
    catch(...)
    {
        cout<<"Invalid Values for a book object. \n";
    }

    //while(true){
    //apple.check_out_in();}
}