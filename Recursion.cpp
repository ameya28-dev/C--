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

    return 0;
}