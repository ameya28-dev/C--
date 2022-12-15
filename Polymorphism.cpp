#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Complex{
    private:
        int real, imag;
    public:
        Complex(int a=0, int b=0){
            real = a;
            imag = b;
        }

        Complex operator + (Complex const &obj){
            Complex result;
            result.imag = imag + obj.imag;
            result.real = real + obj.real;
            return result;
        }

        void display(){
            cout << real << " + i" << imag << endl;
        }
};

int main(){
    Complex c1(12,7), c2(8,5);
    Complex c3 = c1+c2;
    c3.display();

    return 0;
}