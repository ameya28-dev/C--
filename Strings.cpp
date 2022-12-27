#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    // string str;
    // getline(cin, str);
    // cout << str << endl;

    string abc = "njnlsn skjn;vkv/sm vlksnalkmv/l  amk l ";
    abc.clear();
    cout << abc << endl;

    string s1 = "abc";
    string s2 = "abc";

    if(s1.compare(s2)) cout << "Strings are not equal" << endl;
    else cout << "Strings are equal" << endl;

    string s = "gubjadbiulkjcnkcnlkjnlkjjcn";
    sort(s.begin(), s.end());
    cout << s << endl;

    // Convert all characters to upper or lower
    string str = "AhbbajABDJubnlckoq";
    
    // Upper case
    for(int i=0; i<str.length(); i++)
        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
    
    cout << str << endl;

    // Lower Case
    for(int i=0; i <str.length(); i++)
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
    
    cout << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;

    // Form the biggest number from the numeric string
    string str_num = "46800988770236785";
    sort(str_num.begin(), str_num.end(), greater<char>());
    cout << str_num << endl;

    // Return character and its frequency that appears the most in a string
     

    return 0;
}