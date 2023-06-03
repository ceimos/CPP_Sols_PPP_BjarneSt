#include <vector>
#include <string>

struct ISBN
{
    ISBN(int int1, int int2, int int3, char char1) :a{int1}, b{int2}, c{int3}, d{char1} {};
    int a; int b; int c; char d;
};

enum class Genre{Fiction, Biography, Periodical, Children, NonFiction, undefined};

class Patron
{
    private:
        std::string name;
        int card_seq;
        int fee;

    public:
        Patron(std::string name_, int card_seq_, int fee_) :name{name_}, card_seq{card_seq_}, fee{fee_}{};
        const std::string get_name() const{return name;}
        const int get_card_seq() const {return card_seq;}

        //DUEs and FEEs
        int set_fee(int fee_){fee = (fee_>=0) ? fee_ : -1*fee_;} //a positive fee.
        const int get_dues(){return fee;}
};

class Book
{
    private:
        ISBN isbn;
        std::string title;
        std::string author;
        std::string copyright;
        Genre genre{Genre::undefined};
        bool checked_out{false};

    public:
        Book(ISBN isbn_, std::string title_, std::string author_, std::string copyright_, Genre genre_);
        const ISBN get_isbn() const {return isbn;}
        const std::string get_title() {return title;}
        const std::string get_author() {return author;}
        const std::string get_copyright() {return copyright;}
        const Genre get_genre(){return genre;}
        const bool is_available() {return checked_out;}
        void check_out_in();
        int check_isbn();
};

struct Transaction
{
    Book book;
    Patron patron;
    string date;

    Transaction(Book& book_, Patron& patron_, std::string& date_) :book{book_}, patron{patron_}, date{date_}{};
};

class Library
{
    private:
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;

    public:
        const void add_book(const Book& book_){books.push_back(book_);}
        const void add_patron(const Patron& patron_){patrons.push_back(patron_);}
        const void add_transaction(const Transaction& transaction_){transactions.push_back(transaction_);}

        //check out. Check if user and book both exists.

        void check_out(Book& book_, Patron& patron_);

       void patrons_with_dues();
};
