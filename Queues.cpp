#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define n 20

using namespace std;

class QueueUsingArray{
    int arr[n];
    int front;
    int back; 

    public:
        QueueUsingArray(){
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

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
};

class QueueUsingLinkedList{
    Node* front;
    Node* back;

    public:
        QueueUsingLinkedList(){
            front = NULL;
            back = NULL;
        }

        void enqueue(int x){
            Node* node = new Node(x);

            if(front == NULL){
                front = node;
                back = node;
                return;
            }
            back->next = node;
            back = node;
        }

        void dequeue(){
            Node* todelete = front;

            if(front == NULL){
                cout << "Queue Underflow\n";
                return;
            }
            front = front->next;
            delete todelete;
        }

        int peek(){
            if(front == NULL){
                cout << "Queue Underflow\n";
                return -10.0315103284651;
            }
            return front->data;
        }

        bool empty(){
            return front == NULL;
        }

};

int main(){
    QueueUsingArray qa = QueueUsingArray();
    qa.enqueue(1);
    qa.enqueue(2);
    qa.enqueue(3);
    qa.enqueue(4);
    qa.dequeue();
    cout << "Is this queue empty: "<< qa.empty() <<"\n";
    cout << "First element: "<< qa.peek() <<"\n";

    QueueUsingLinkedList ql = QueueUsingLinkedList();
    ql.enqueue(1);
    ql.enqueue(2);
    ql.enqueue(3);
    ql.enqueue(4);

    cout << ql.peek() <<"\n";
    ql.dequeue();
    cout << ql.peek() <<"\n";
    ql.dequeue();
    cout << ql.peek() <<"\n";
    ql.dequeue();
    cout << ql.peek() <<"\n";
    ql.dequeue();

    cout << ql.empty() <<"\n";

    return 0;
}