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

int main(){
    int isarraysorted[] = {1,3,3,4,5,6,7};
    cout << "Is Array Sorted? " << isArraySorted(isarraysorted, sizeof(isarraysorted)/sizeof(int)) << endl;
    
    int number = 10;
    cout << "Descending Order: " << endl;
    dec(number);

    cout << "Increasing Order: " << endl;
    inc(number);

    return 0;
}