#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    //base cases
    // if(n == 0 || n == 1){
    //     return 1;
    // }
    // if(n == 2){
    //     return 2;
    // }
    long * waysToReach = new long[n+1];
    waysToReach[0] = 1;
    waysToReach[1] = 1;
    waysToReach[2] = 2;
    for(int i=3 ; i<=n ; i++){
        waysToReach[i] = waysToReach[i-1] + waysToReach[i-2] + waysToReach[i-3];
    }
    long ans = waysToReach[n];
    delete [] waysToReach;
    return ans;
}


int main(){

    int steps;
    cin >> steps;
    int ways = staircase(steps);
    cout << ways << endl;
    return 0;
}