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

    return 0;
}