#include ".\std_lib_facilities.h"

//tokens
class Token
{
    public:
        char type;
        double value;

        Token(char k): type(k), value(0){}
        Token(char k,double v):type(k), value(v){}
};

class Token_stream
{
    public:
        Token_stream();
        Token get();
        void putback(Token t);
    private:
        bool full{false};
        Token buffer; //keeps token from putback()
};

Token_stream::Token_stream()
:full(false),buffer(0){}

void Token_stream::putback(Token t)
{
    if(full) error("putback() into a full buffer");
    buffer=t; //else puts the token t into the buffer
    full=true;
}

Token Token_stream::get()
{
    if(full){
        full=false; return buffer; //if we already have a token in the buffer it returns that while setting full to false.
    }
    char ch;
    cin>>ch; // reads the input

    switch(ch){
        case 'q': case '=': case '(' : case ')': //changes ';' to '=' for printing result
        case '{' : case '}' : //EX2 added '{' and '}'
        case '+': case '-' : case '/': case '*':  case '!': //ex3 added ! (factorial function)
            return Token(ch);
        case '.': case '0': case '1' : case '2': case '3': case '4': case '5' : case '6' : case '7': case '8': case '9':
            {
                cin.putback(ch);
                double val;
                cin>>val;
                return Token('8',val);
            }
        default:
            cout<<"Bad Token\n"; return 0;
    }
}

Token_stream ts; // declaring a token stream object here, so that we can access the get() and putback() functions.
double expression(); // pre-declaring this, so that the primary() could call it.

//To deal with numbers and '(' and ')' and '{}' 
double primary()
{
    Token t=ts.get();
    switch (t.type){
        case '(':
        {
            double d = expression();
            t=ts.get();
            if (t.type!=')'){error("Expected ')'");}
            return d; 
        }
        case '{' :
        {
            double d =expression();
            t=ts.get();
            if (t.type!='}'){cout<<"expected '}'";}
            return d;
        }
        case '8':
            return t.value;
        default: cout<<"primary expected !\n"; return 0;
    }
}

double secondary() //Factorial operation EXercise 3
{
    double left=primary();
    Token t=ts.get();

    while(true)
    {
        if(t.type=='!')
        {
            int x= left; //converts double to int, digits after decimal get truncated.
            if(x==0) return 1;
            for(int i=x-1;i>0;--i){x*=i;}
            left=x; //converts integer to double, nothing gets truncated.
            t=ts.get();
        }
        else{
            ts.putback(t);
            return left;
        }
    }
}

double term()
{
    double left=secondary();
    Token t=ts.get();
    while(true){
        switch(t.type){
        
            case '*':
                left*=primary();
                t=ts.get();
                break;
            case '/':
            {
                double d=primary();
                if(d==0)error("divide by zero");
                left/=d;
                t=ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression(){
    double left=term();
    Token t=ts.get();
    while(true)
    {
        switch(t.type)
        {
            case '+':
                left+=term();
                t=ts.get();
                break;
            case '-':
                left-=term();
                t=ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

vector<Token> tokens_store; //Stores all tokens here

int main()
{
    double val = 0;

    //Greetings

    cout<<"Ceimos' Calculator\n"
    <<"available operations = *,-,*,/ use of '(' and ')' permitted.\n"
    <<"use ';' to print result and 'q' to quit and exit.\n \n";
    
    while(cin){
        Token t=ts.get();

        if(t.type=='q'){break;}
        if(t.type=='=')//changes ';' to '=' for printing result
        {
            cout<<val<<'\n';
        }
        else
        {
            ts.putback(t);
        }
        val=expression();
    }
}