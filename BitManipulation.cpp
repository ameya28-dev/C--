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
    int arr[3] = {1,2,3};
    cout << "All subsets: " << endl;
    generateSubsets(arr, 3);

    return 0;
}