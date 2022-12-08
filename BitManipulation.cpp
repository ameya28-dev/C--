#include <iostream>
#include <string>

using namespace std;

int getBit(int n, int pos){
    return (n & (1<<pos)) != 0;
} 

int main(){

    cout << getBit(5,1); //0101 1010 0000


    return 0;
}