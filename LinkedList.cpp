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

// Reverse a Linked List Iteratively
// Need 3 pointer to be able to traverse linked list
Node* reverseLLIteratively(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

Node* reverseLLRecursively(Node* &head){
    // Base Case: If LL is empty or has only one node
    if(head == NULL || head->next == NULL) return head;

    Node* newhead = reverseLLRecursively(head->next);
    // Assuming recursion will provide a smaller linked list
    // We have to reverse the next node to head towards the node
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

Node* reverseKNodes(Node* &head, int k){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    int count=0;

    while(currptr != NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++; 
    }

    if(nextptr != NULL){
        head->next = reverseKNodes(nextptr,k);
    }

    return prevptr;
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

bool detectCycle(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast ==  slow) return true;
    }

    return false;
}

// Assuming we have found a cycle in the linked list
void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while(slow!=fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int main(){
    Node* head = NULL;
    insertNodeAtTail(head,1);
    insertNodeAtTail(head,2);
    insertNodeAtTail(head,3);
    insertNodeAtHead(head,0);
    insertNodeAtHead(head,4);
    cout << "Original Linked List: ";
    display(head);
    cout << "If node 5 is present: " << searchNode(head,5) << endl;
    cout << "If node 3 is present: " << searchNode(head, 3) << endl;
    deleteNode(head,4);
    cout << "LinkedList after removing 4:\t";
    display(head);

    insertNodeAtTail(head,4);
    insertNodeAtTail(head,5);
    cout << "Reversing the linked list iteratively:\t";
    Node* newiLL = reverseLLIteratively(head);
    display(newiLL);
    cout << "Reversing the linked list recursively:\t";
    Node * newrLL = reverseLLRecursively(newiLL);
    display(newrLL);

    cout << "Reversing k nodes of a linked list:\t";
    Node* newkll = reverseKNodes(newrLL,2);
    display(newkll);

    Node* cyclehead = NULL;
    insertNodeAtTail(cyclehead,1);
    insertNodeAtTail(cyclehead,2);
    insertNodeAtTail(cyclehead,3);
    insertNodeAtTail(cyclehead,4);
    insertNodeAtTail(cyclehead,5);
    insertNodeAtTail(cyclehead,6);
    makeCycle(cyclehead,3);

    cout << "Is there a cycle present:\t" << detectCycle(cyclehead) << endl;
    cout << "Linked List after Removing cycle:\t";
    removeCycle(cyclehead);
    display(cyclehead);

    return 0;
}