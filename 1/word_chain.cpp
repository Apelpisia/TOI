#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, n; cin >> l >> n;
    string prev; cin >> prev;
    for(int i=0; i<n-1; i++){
        int d=0; string ip; cin >> ip;
        for(int i=0; i<l; i++){
            if(ip[i]!=prev[i]) d++;
            if(d>2){cout << prev; return 0;}
        } prev = ip;
    } cout << prev;

    return 0;
}
