#include <iostream>
#include <string>
#include <algorithm>    

using namespace std;

class Node{
    public:
        int data; 
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
}; 

void insertNodeAtTail(Node* &head, int val){ 
    Node* n = new Node(val);  

    if(head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = n; 
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int findLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

Node* appendKNodes(Node* &head, int k){
    int l = findLength(head);
    Node* newTail;
    Node* newHead;
    Node* tail = head;
    k = k%l;
    int count = 1;

    while(tail->next!=NULL){
        if(count == l-k) newTail = tail;
        if(count == l-k+1) newHead = tail;
        count++;
        tail = tail->next;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}


int main(){
    Node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i <6;i++) insertNodeAtTail(head,arr[i]);
    display(head);
    Node* newhead = appendKNodes(head,3);
    display(newhead);
    
    return 0;
}