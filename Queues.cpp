#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define n 20

using namespace std;

class Queue{
    int arr[n];
    int front;
    int back; 

    public:
        Queue(){
            front = -1;
            back = -1;
        }

        void enqueue(int x){
            if(back == n-1){
                cout << "Queue Overflow\n";
                return;
            }

            back++;
            arr[back] = x;

            if(front == -1){
                front++;
            }
        }



};

int main(){

    return 0;
}