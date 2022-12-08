#include <iostream>
#include <string>

using namespace std;

int getBit(int n, int pos){
    return (n & (1<<pos)) != 0;
} 

int setBit(int n, int pos){
    return (n | (1 << pos));
}

int main(){

    cout << "Get Bit: " << getBit(5,1) << endl; //0101 1010 0000
    cout << "Set Bit: " << setBit(5,1) << endl;

    return 0;
}