#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool myComparator(pair<int,int> p1, pair<int,int> p2){
    return p1.second <= p2.second;
}

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
    
    pair<int,char> p1;
    p1.first = 2;
    p1.second = 'f';

    pair<int,char> p2 = make_pair(4,'d');

    // Program to reduce an array
    // Update smallest element to 0, next to 1 and so on until len(arr) - 1
    int arr[] = {10,16,7,14,5,3,12,9};
    vector <pair<int,int>> vec;

    // Storing key-value pair for every element in arr 
    for(int i=0; i < sizeof(arr)/sizeof(int); i++){
        vec.push_back(make_pair(i,arr[i]));
    }
    
    // Sorting vec using a comparator
    std :: sort(vec.begin(), vec.end(), myComparator);

    // Changing values in array
    for(int i = 0; i < vec.size(); i++){
        arr[vec[i].first] = i;
    }

    // printing Reduced array
    cout << endl << "Reducing array: " << endl;
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        cout << arr[i] << "\t";
    }

    return 0;
}
class Solution {
public:
    int sumofdigits(int n){
        int ans = 0;
        while(n>0){
            ans += n%10;
            n = n/10;
        }
        return ans;
    }

    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> ballcount;
        int index;
        int maximum = 0;
        for(int i = lowLimit; i<= highLimit; i++){
            index = sumofdigits(i);
            if(ballcount.find(index) != ballcount.end()){
                maximum = max(maximum, ballcount[index]+1);
            }
            (ballcount[index])++;
        }
        // unordered_map<int, int>:: iterator p;
        // int maximum = 0;
        // for(p = ballcount.begin(); p != ballcount.end(); p++){
        //     if(maximum < p->second) maximum = p->second;
        // }

        return maximum;
    }
};