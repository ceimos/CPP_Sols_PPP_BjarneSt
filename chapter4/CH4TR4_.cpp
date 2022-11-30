#include ".\std_lib_facilities.h"

int main()
{   
    char alphabet_char;
    int alphabet_int;
    
    cout<<"---Small Lettere --- \n";
    //Small letter alphabets
    for(int i{0};i<26;++i)
    {
        alphabet_int='a'+i; alphabet_char=alphabet_int;
        cout<<alphabet_char<<"\t"<<alphabet_int<<"\n";
    }
    cout<<"\n --- Capital Letters --- \n";
    //Capital letter alphabets
    for(int i{0};i<26;++i)
    {
        alphabet_int='A'+i; alphabet_char=alphabet_int;
        cout<<alphabet_char<<"\t"<<alphabet_int<<"\n";
    }
    cout<<"\n---Capital Small Adjacent Print---\n";
    for(int i{0};i<26;++i)
    {
        alphabet_int='a'+i; alphabet_char=alphabet_int;
        cout<<alphabet_char<<"\t"<<alphabet_int<<"\t | \t"; //Doesn't create new_line so next print is done adjacently.
        alphabet_int='A'+i; alphabet_char=alphabet_int;
        cout<<alphabet_char<<"\t"<<alphabet_int<<"\n";
    }
}