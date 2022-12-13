#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student{
    public:
        string name;
        int age;
        bool gender;

        Student(){
            cout << "This is a default constructor\n";
        } // Default Constructor

        Student(string s, int i, bool g){
            cout << "This is a Parameterised Constructor\n";
            name = s;
            age = i;
            gender = g;
        } // Parameterised Constructor

        Student(Student &a){
            cout << "This is a Parameterised Constructor\n";
            name = a.name;
            age = a.age;
            gender = a.gender;
        } // Copy Constructor

        void printInfo(){
            cout << "Details:" << endl;
            cout << name << "\t" << age << "\t" << gender << endl;
        } // Method

        ~Student(){
            cout << "Destructor called!" << endl;
        } // Destructor

        bool operator == (Student &a){
            if (name == a.name && age == a.age && gender == a.gender)
                return 1;
            else return 0;
        } // Operator Overloading
        
};

int main(){
    Student a("Ameya", 22, 0);
    Student b;
    Student c = a;

    a.printInfo();
    b.printInfo();
    c.printInfo();

    if(b==a) cout << "Same" << endl;
    else cout << "Not Same" <<  endl;

    return 0;
}