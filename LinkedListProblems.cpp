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

void intersectLinkedLists(Node* &head1, Node* &head2,int pos){
    Node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}


int findIntersectionPoint(Node* &head1, Node* &head2){
    int l1 = findLength(head1);
    int l2 = findLength(head2);

    int d;
    Node* ptr1;
    Node* ptr2;
    
    if(l1>=l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL) return -1; 
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2) return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

Node* mergeLLIteratively(Node* &head1, Node* &head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* dummyNode = new Node(0);
    Node* ptr3 = dummyNode;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while(ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next; 
    }

    while(ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next; 
    }

    return dummyNode->next;
}

Node* mergeLLRecursively(Node* &head1, Node* &head2){
    
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeLLRecursively(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeLLRecursively(head1, head2->next);
    }

    return result;
}

void evenAfterOdd(Node* &head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;        
    }

    odd->next = evenStart;
    if(odd->next != NULL){
        even->next = NULL;
    }
}

int main(){
    cout << "Append K Nodes:" << "\n";
    Node* head = NULL;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i <6;i++) insertNodeAtTail(head,arr[i]);
    display(head);
    Node* newhead = appendKNodes(head,3);
    display(newhead);
    cout << "\n";

    cout << "Find intersection in Linked List: " << "\n";
    Node* head1 = NULL;
    Node* head2 = NULL;
    for(int i=0;i <6;i++) insertNodeAtTail(head1,arr[i]);
    insertNodeAtTail(head2,9);
    insertNodeAtTail(head2,10);
    intersectLinkedLists(head1, head2, 3);
    display(head1);
    display(head2);
    cout << findIntersectionPoint(head1,head2) << '\n';
    cout << "\n";
    
    cout << "Merge 2 sorted Linked Lists: " << "\n";
    Node* Isortedhead1 = NULL;
    Node* Isortedhead2 = NULL;
    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};
    for(int i=0;i <4;i++) insertNodeAtTail(Isortedhead1,arr1[i]);
    for(int i=0;i <3;i++) insertNodeAtTail(Isortedhead2,arr2[i]);
    display(Isortedhead1);
    display(Isortedhead2);

    cout << "Iterative" << "\n";
    Node* newIMerged = mergeLLIteratively(Isortedhead1,Isortedhead2);
    display(newIMerged);
    
    cout << "Recursive" << "\n";
    Node* Rsortedhead1 = NULL;
    Node* Rsortedhead2 = NULL;
    for(int i=0;i <4;i++) insertNodeAtTail(Rsortedhead1,arr1[i]);
    for(int i=0;i <3;i++) insertNodeAtTail(Rsortedhead2,arr2[i]);
    display(Rsortedhead1);
    display(Rsortedhead2);
    Node* newRMerged = mergeLLRecursively(Rsortedhead1,Rsortedhead2);
    display(newRMerged);
    cout << "\n";

    cout << "Even After Odd: " << "\n";
    Node* headeo = NULL;
    for(int i=0;i <6;i++) insertNodeAtTail(headeo,arr[i]);
    display(headeo);
    evenAfterOdd(headeo);
    display(headeo);
    cout << "\n";

    return 0;
}