#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#define n 100

using namespace std;

class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "No element to pop\n";
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
             cout << "No element in the stack\n";
             return -1; 
        }

        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

void reverseSentence(string s){
    stack<string> st;

    for(int i=0; i < s.length(); i++){
        string word = "";

        while(s[i] != ' ' && i<s.length()){
            word += s[i];
            i++;
        }

        st.push(word);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";
}

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int topelement =  st.top();
    st.pop();
    insertAtBottom(st, topelement);
}

void reverseStack(stack<int> st){
    if(st.empty()) return;

    int element = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,element); 
}

int main(){
    Stack st = Stack();
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << "\n";
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() <<"\n";

    string s = "Hey, how are you doing?";
    reverseSentence(s);

    stack<int> reversestack;
    reversestack.push(1);
    reversestack.push(2);
    reversestack.push(3);
    reversestack.push(4);

    reverseStack(reversestack);
    while(!reversestack.empty()){
        cout << reversestack.top() << " ";
        reversestack.pop();
    }

    return 0;
}