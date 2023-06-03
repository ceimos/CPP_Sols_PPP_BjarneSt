#include <iostream> //includes <string> however explicit inclusion is a good practice.
#include <vector>

#include "library.h"

using namespace std;


bool is_fee_due(Patron& patron_) //Helper function - not a language feaure, but a design choice. WHY?? representation is irrevant to this f(). 
{
    return (patron_.get_dues()==0) ? false : true; 
}

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

bool operator==(const Book& book1, const Book& book2)
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

bool operator==(const Patron& patron_1,const Patron& patron_2)
{
    return patron_1.get_card_seq()==patron_2.get_card_seq();
}

void Book::check_out_in()
{
    if(is_available()==true) 
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
            cout<<"\n Book is available for checkout! \n";
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

void Library::check_out(Book& book_,Patron& patron_)
{
    bool book_is_avail{false};
    bool patron_is_avail{false};

    for (Book& a_book:books)
    {
        if(a_book==book_ && book_.is_available()==true)
        {
            book_is_avail=true; // checks both if is part of library, and if is available
        }
        else {cout<<"book is not available \n";}
    }

    for (Patron& a_patron:patrons)
    {
        if(a_patron==patron_ && patron_.get_dues() != 0) //second condition won't be evaluated if first is false. - Short Circuit Evaluation.
        {
            patron_is_avail=true;
        }
        else{cout<<"Error : The User Does not exist OR dues aren't clear.! \n";}
    }

    if(patron_is_avail && book_is_avail)
    {
        book_.check_out_in();
        string date_="date_"; //GET date object when checking out. Not taking care of this, now.
        Transaction new_transaction={book_,patron_,date_};
        transactions.push_back(new_transaction);
    }
}

void Library::patrons_with_dues()
{
    vector<Patron> patrons_with_dues;

    for(Patron& patron_:patrons)
    {
        if(patron_.get_dues()!=0){patrons_with_dues.push_back(patron_);}
    }

    for(Patron& patron_:patrons_with_dues)
    {
        cout<<"["<<patron_.get_name()<<" "<<patron_.get_dues()<<" "<<patron_.get_card_seq()<<"]\n";
    }
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

        Patron pat_test_1{"patron_test_1",1234,30};
        cout<<pat_test_1.get_name()<<pat_test_1.get_card_seq()<<pat_test_1.get_dues()<<"\n";

        //test library
        //add books
        //add patron
        //checkout with paron and book.
        //TEST all the function, I have tested none. 
    }
    catch(...)
    {
        cout<<"Invalid Values for a book object. \n";
    }
}