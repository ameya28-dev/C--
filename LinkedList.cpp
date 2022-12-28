#include <iostream>
#include <string>
#include <algorithm>    

using namespace std;

// Defining a linked list
class Node{
    public:
        int data; // datatype of value to be stored in the node
        Node* next; // pointer of name next pointing to the next node, hence Node*

        // Constructor
        Node(int val){
            data = val;
            next = NULL;
        }
}; 

// A method to insert a node at tail
void insertNodeAtTail(Node* &head, int val){ // Passing the adress of 'head' pointer to the method and not its value     
    Node* n = new Node(val);  // Creating a pointer to the node n created using the constructor

    if(head == NULL) {
        head = n;
        return;
    } // No traversing, last node will become the first node

    Node* temp = head; // Creating a pointer for temp node that is same as head 
    while(temp->next != NULL){ // -> is used to access members of a class or structure using pointers
        temp = temp->next; // traversing to next node
    }
    temp->next = n; // Assigning n as the next node of temp (last node after loop)
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert a node at head
// 1. Point new node to first node
// 2. Point head to new node
void insertNodeAtHead(Node* &head, int val){
    Node* n = new Node(val); // Create a new node
    n->next = head; // Point new node to first node 
    head = n; // Point head to new node 
}

// If a node exists
bool searchNode(Node* head, int key){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Delete a node
void deleteNode(Node* &head, int val){
    if(head == NULL){
        return;
    }

    if(head->data == val){
        if(head->next == NULL){
            Node* todelete = new Node(val);
            delete todelete;
            return;
        }
        else{
            Node* todelete = head;
            head = head->next;
            delete todelete;
            return;
        }
    }
    
    Node* temp = head;

    while(temp->next->data != val){
        temp = temp->next;
    }
    Node* todelete = temp->next; // this has to be deleted to avoid memory leak
    temp->next = temp->next->next;
    delete todelete;
}

int main(){
    Node* head = NULL;
    insertNodeAtTail(head,1);
    insertNodeAtTail(head,2);
    insertNodeAtTail(head,3);
    // insertNodeAtHead(head,0);
    display(head);
    cout << "If node is present: " << searchNode(head,5) << endl;
    cout << "If node is present: " << searchNode(head, 3) << endl;
    deleteNode(head,1);
    display(head);

    return 0;
}