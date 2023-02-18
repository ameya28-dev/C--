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

        void dequeue(){
            if(front == -1 || front > back){
                cout << "No element in the Queue\n";
                return;
            }
            front++;
        }

        int peek(){
            if(front == -1 || front > back){
                cout << "No element in the Queue\n";
                return -1;
            }
            return arr[front];
        }

        bool empty(){
            if(front == -1 || front > back){
                return true;
            }
            return false;
        }

};

int main(){
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    cout << "Is this queue empty: "<< q.empty() <<"\n";
    cout << "First element: "<< q.peek() <<"\n";

    return 0;
}