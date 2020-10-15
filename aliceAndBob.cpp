#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int decodeWays(string code){

    int len ;
    long long int decoding[5001];

    if(code == "0"){
        return -1;
    }      
    len = code.size();
    for(int i=0 ; i<5000 ;i++){
        decoding[i]=0; 
    }
    decoding[0] = 1;
    for(int i=1 ; i<len; i++){
        int digit =(code[i-1] - '0') * 10 + (code[i] - '0');
        if(code[i] != '0'){
            decoding[i] = decoding[i-1];
        }
        if(digit >= 10 && digit <= 26 && i>1){
            decoding[i] += decoding[i-2];
        }
        else if(digit >= 10 && digit <= 26){
            decoding[i]++;
        }  
        decoding[i] = decoding[i] % mod;
    }
    return decoding[len-1];
}
int main(){
    while(1){
        string str;
        cin >> str;
        if(str == "0")
                break;
        int ans = decodeWays(str);
        ans = (ans == -1) ? 0 : ans;
        cout << ans << endl;
    }
    return 0;
}


