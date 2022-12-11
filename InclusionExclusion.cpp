#include <iostream>
#include <string>

using namespace std;

int divisible(int n, int a, int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    return c1+c2-c3;
}

int gcd(int m, int n){
    if(n == 0) return m;
    else return(gcd(n,m%n));
}

int main(){
    int num,a,b;
    cout << "Enter input for count of numbers divisible:" << endl;
    cin >> num >> a >> b; 
    cout << divisible(num,a,b) << endl;

    int m,n;
    cout << "Enter 2 numbers to find GCD:" << endl;
    cin >> m >> n;
    cout << gcd(max(m,n), min(m,n));

    return 0;
}