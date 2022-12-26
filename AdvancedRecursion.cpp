#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void permutationOfString(string s, string ans){
    if(s.length()==0){
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        string ros = s.substr(0,i) + s.substr(i+1);
        permutationOfString(ros, ans+ch);
    }
}

int countOfSteps(int s, int e){
    if(s == e) return 1;
    if (s > e) return 0;
    
    int count  = 0;
    for(int i = 1; i <= 6; i++){
        count += countOfSteps(s+i,e);
    }      

    return count;
}

int countPathofMaze(int n, int i, int j){
    if(i == n-1 && j == n-1) return 1;

    if(i >= n || j >= n) return 0;

    return countPathofMaze(n, i+1,j) + countPathofMaze(n,i,j+1);
}

int countOFTile(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;

    return countOFTile(n-1) + countOFTile(n-2);
}

int pairingFriends(int n){
    if(n == 0 || n == 1 || n == 2) return n;

    return pairingFriends(n-1) + (n-1)*pairingFriends(n-2);
}

int knapsack(int value[], int weight[], int n, int W){
    if(n==0 || W == 0) return 0;

    if(weight[n-1] > W) return knapsack(value, weight, n-1, W);

    return max(knapsack(value, weight, n-1, W-weight[n-1]) + value[n-1],knapsack(value, weight, n-1, W));
}

int main(){
    // All permutations of a string
    cout << "All permutations of a string" << endl;
    permutationOfString("ABCD","");
    cout << endl;
    
    // Count the number of ways to reach from start to end with allowable step
    // length from 1 to 6
    cout << "Number of ways to reach end on a gameboard: " << endl;
    cout << countOfSteps(0,3);
    cout << endl;

    // Count the number of paths possible in a maze
    // Start from top left and move only one step to the right or bottom at once
    cout << "Number of possible paths in a 2D square maze" << endl;
    cout << countPathofMaze(3,0,0) << endl << endl;

    // Count the number of ways a "2*1" tile could tile a "2*n" tile
    cout <<  "number of ways a \"2*1\" tile could tile a \"2*n\" tile" << endl;
    cout << countOFTile(4) << endl << endl;

    // Friends pairing problem
    // Number of ways in which n friends can be single or paired up
    cout << "Friends pairing problem" << endl;
    cout << pairingFriends(4) << endl << endl;

    // 0-1 Knapsack Problem
    cout << "0-1 Knapsack Problem" << endl;

    int wt[] = {10,20,30};
    int val[] = {100,50,150};
    int W = 50;
    cout << knapsack(val,wt,sizeof(wt)/sizeof(int),W); 

    return 0;
}