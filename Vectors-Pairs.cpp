#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    cout << "Address of v: " << &v <<endl;
    
    cout << "Traversing vector using indices: " << endl;
    for(int i=0; i< v.size(); i++){
        cout << v[i] <<"\t";
    }

    cout << endl << "Traversing vector using iterator:" << endl;
    vector<int> :: iterator ptr;
    for(ptr = v.begin(); ptr != v.end(); ptr++){
        cout << *ptr <<"\t";
    }

    cout << endl << "Traversing vector using auto:" << endl;
    for (auto x:v){
        cout << x <<"\t";   
    }
    
    v.pop_back();

    vector<int> v2 (3,80);
    cout << endl << "Address of v2: " << &v2 << endl;
    swap(v,v2);

    cout << "Address of v: " << &v << endl << "Address of v2: " << &v2 << endl;

    sort(v2.begin(), v2.end());
    for(vector<int>:: iterator it = v2.begin(); it!=v2.end(); it++){
        cout << *it << "\t";
    }

    return 0;
}