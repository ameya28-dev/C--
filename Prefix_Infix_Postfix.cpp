#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int opPrecedence(char c){
        if (c == '^') return 3;
        else if (c == '*' || c == '/' ) return 2;
        else if (c == '+' || c == '-' ) return 1;
        else return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res = "";

    for(int i = 0; i <= s.length()-1; i++){

        if((s[i] >= 'a' && s[i] <= 'z' )|| (s[i] >= 'A' && s[i] <= 'Z')) res += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if (s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else{
            while(!st.empty() && opPrecedence(s[i]) < opPrecedence(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }

    while(!st.empty()){
            res += st.top();
            st.pop();
    }


    return res;
}


int prefixEvaluation(string s){
    stack<int> st;

    for(int i = s.size()-1; i>=0; i--){
        if(s[i]>='0' && s[i] <= '9') st.push(s[i] - '0');
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(op1^op2);
                break;
            }            
        }
    }
    return st.top();
}

int postfixEvaluation(string s){
    stack<int> st;

    for(int i = 0; i <= s.size()-1 ; i++){
        if(s[i]>= '0' && s[i] <= '9') st.push(s[i] - '0');
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(op1^op2);
                break;
            }            
        }
    }
    return st.top();
}

int main(){
    cout << "Prefix Evaluation:\n";
    cout << prefixEvaluation("-+7*45+20") << "\n\n";

    cout << "Postfix Evaluation:\n";
    cout << postfixEvaluation("46+2/5*7+") << "\n\n";

    cout << "Convert Infix expression to Postfix :\n";
    cout << infixToPostfix("(a-b/c)*(a/k-l)") << "\n\n";

    return 0;
}