//given string, no leading 0s, find sum of all its substrings
//For 1234 : 4,34,234,1234 | 3,23,123 | 2,12 | 1
//Dynamic approach since using last result we calculate current answer

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int sumSubstring(string s){

    long long totalSum = s[0] - '0';    //if string length is 1
    long long prevSum = s[0] - '0';     //maintaining substring sum up to just prev position, here firts elem

    for(int i = 1; i < s.length(); i++){

        prevSum = (prevSum * 10) + ((s[i]-'0') * (i+1));
        prevSum = prevSum % MOD;    //since we take mod at each step, the long datatype total sum dont exceed int
        totalSum = (totalSum + prevSum) % MOD;  //sum of int might exceed int, so take mod
    }
    return totalSum;    //this auto returns the int value contained in totalSum
}
int main(){

    string str;
    cin >> str;
    int ans = sumSubstring(str);
    cout << ans << endl;
    return 0;
}