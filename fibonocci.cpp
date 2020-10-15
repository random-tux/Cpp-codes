#include<bits/stdc++.h>
using namespace std;

//General recursive fibonocci func O(2^n) : 2^n function calls happen
int fib1(int n){

    if(n==1 || n==0){
        return 1;
    }
    return fib1(n-1) + fib1(n-2);
}

//Dynamic approach O(n) : 2n function calls happen, storing result of work that we already done
int fib2(int n, int* arr){

    if(n==1 || n==0){
        return 1;
    }
    if(arr[n] > 0){
        return arr[n];
    }
    int output = fib2(n-1 ,arr) + fib2(n-2 ,arr);
    arr[n] = output;
    return arr[n];
}

//Iterative fibonocci func, O(n) : simply traversing through arr of n 
int fib3(int n){
    int* arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2 ; i<=n ;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    int output = arr[n];
    delete [] arr;
    return output;
}

int main(){

    int n;
    cin >> n;
    cout << fib3(n) << endl;
    return 0;
}