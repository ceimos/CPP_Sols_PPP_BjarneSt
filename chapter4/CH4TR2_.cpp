#include ".\std_lib_facilities.h"

int main()
{   
    char alphabet_char;
    int alphabet_int;
    
    int i{0};

    while(i<26)
    {
        alphabet_int='a'+i; //converts 'a' to its int, adds i
        alphabet_char=alphabet_int; //converts the above int to equivalent char.
        cout<<alphabet_char<<"\t"<<alphabet_int<<"\n";
        ++i;
    }
} 