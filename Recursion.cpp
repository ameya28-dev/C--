#include <iostream>
#include <string>

using namespace std;

bool isArraySorted(int arr[], int n){
    if (n==1) return true;

    return arr[0] < arr[1] && isArraySorted(arr+1, n-1);
}

void dec(int n){
    if (n==1){
        cout << 1 << endl;
        return;
    }

    cout << n << endl;
    dec(n-1);
}

void inc(int n){
    if (n==1){
        cout << 1 << endl;
        return;
    }

    inc(n-1);
    cout << n << endl;
}

void reverseAString(string str){
    if (str.length() == 0) return;

    reverseAString(str.substr(1));
    cout << str[0];
}

void replacePi(string s){
    if (s.length() == 0) return;

    if(s[0] == 'p' && s[1] == 'i'){
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else{
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n, char src, char dest, char helper){
    if (n==0) return;

    towerOfHanoi(n-1,src,helper,dest);
    cout << "Move from " << src << " to " << dest <<endl;
    towerOfHanoi(n-1,helper,dest,src);
}

string removeDuplicates(string s){
    if(!s.length()){
        return "";
    }

    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));

    if(ch == ans[0]){
        return ans;
    }
    else return (ch+ans);
}

string moveAllXToEnd(string s){
    if(s.length()==0) return "";

    char ch = s[0];
    string ans = moveAllXToEnd(s.substr(1));

    if(ch == 'x') return ans+ch;
    else return ch+ans;
}

string allSubstr(string s, string ans){
    if (s.length() == 0) {
        cout << ans << endl;
        return "";
    }

    char ch = s[0];
    string sub = s.substr(1);

    allSubstr(sub,ans);
    allSubstr(sub, ans+ch);
}

int main(){

    // Find if array is sorted
    int isarraysorted[] = {1,3,3,4,5,6,7};
    cout << "Is Array Sorted? " << isArraySorted(isarraysorted, sizeof(isarraysorted)/sizeof(int)) << endl;
    
    // Print till n in descending and ascending order
    int number = 10;
    cout << "Descending Order: " << endl;
    dec(number);

    cout << "Increasing Order: " << endl;
    inc(number);

    // Reverse a string
    reverseAString("binod");
    cout << endl;

    // Replace pi with 3.14 in a string
    replacePi("pioosppspincjpi");
    cout << endl;

    // Tower of Hanoi
    towerOfHanoi(6,'A','C','B');
    cout << endl;

    // Remove all consecutive duplicates from a string
    cout << removeDuplicates("aaabaahcnnncddssssa") << endl;

    // Move all 'x' to the end of a string
    cout << moveAllXToEnd("xakdmxjjjbbxbbxxxxuxx") << endl;

    // All substrings of a string
    allSubstr("ABCD","");

    return 0;
}