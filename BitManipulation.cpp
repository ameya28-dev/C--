#include <iostream>
#include <string>

using namespace std;

int getBit(int n, int pos){
    return (n & (1<<pos)) != 0;
} 

int setBit(int n, int pos){
    return (n | (1 << pos));
}

int clearBit(int n, int pos){
    return (n & ~(1<<pos));
}

int updateBit(int n, int pos, int bit){
    n = n & ~(1<<pos);
    return (n | (bit << pos));
    // or this 
    // return ((n & ~(1<<pos)) | (bit << pos));
}

bool isPowerOf2(int n){
    return n && !(n & (n-1)) ;
}

int numberOfOnes(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}

void generateSubsets(int arr[], int n){
    for(int i = 0; i<(1<<n); i++){
        for(int j = 0; j < n; j++){
            if (i & (1<<j)){
                cout << arr[j] << "\t"; 
            }
        }
        cout << endl;
    }
}

int findUniqueNumber(int arr[], int n){
    int xorsum = 0;
    for(int i = 0; i<n; i++){
        xorsum ^= arr[i];
    }
    return xorsum;
}

void find2UniqueNumbers(int arr[], int n){
    // Get XOR of all numbers
    int xorsum = 0;
    for(int i = 0; i<n; i++){
        xorsum ^= arr[i];
    }

    // find postion of rightmost set bit in xorsum
    int setbit = 1, pos = 0;
    while(!(xorsum & setbit)){
        pos++;
        setbit <<= 1;
    }
    
    // find 2 unique numbers
    int xorsum2 = 0;
    for(int i = 0; i<n; i++){
        if (getBit(arr[i],pos)) xorsum2 ^= arr[i];
    }

    cout << xorsum2 << "\t" << (xorsum2 ^ xorsum);    
}

int main(){

    cout << "Get Bit: " << getBit(5,1) << endl; //0101 1010 0000
    cout << "Set Bit: " << setBit(5,1) << endl;
    cout << "Clear Bit: " << clearBit(5,2) << endl;
    cout << "Update Bit: " << updateBit(5,3,1) <<endl << endl;

    // Check if a number is power of 2
    cout << "Is 16 a power of 2: " << isPowerOf2(16) << endl;
    cout << "Is 15 a power of 2: " << isPowerOf2(7) << endl << endl;

    // Count of ones in binary form of a number
    cout << "Number of ones in 5: " << numberOfOnes(5) << endl;
    cout << "Number of ones in 0: " << numberOfOnes(0) << endl << endl;

    // Generate all possible subsets of a set
    int setarray[3] = {1,2,3};
    cout << "All subsets: " << endl;
    generateSubsets(setarray, 3);

    // Find number which appears once in an array while the rest appear twice
    int unique1array[] = {1,7,2,2,1};
    cout << "Find unique one: " << findUniqueNumber(unique1array, 5) << endl;

    // Find 2 numbers which appears once in an array while the rest appear twice
    int unique2array[] = {2,99,8,7,8,2};
    cout << "Find 2 unique numbers: ";
    find2UniqueNumbers(unique2array, 6);

    return 0;
}