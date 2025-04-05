#include <bits/stdc++.h>

using namespace std;

int ans[5]={0}; //i v x l c 1 5 10 50 100

void calc(int n){
    int ones = n%10, tens = (n/10)%10, hundreds = n/100;
    if(ones==4){ans[0]++; ans[1]++;}
    else if(ones==9){ans[0]++; ans[2]++;}
    else if(ones<4) ans[0]+=ones;
    else{ans[1]++; ans[0]+=(ones-5);}
    if(tens==4){ans[2]++; ans[3]++;}
    else if(tens==9){ans[2]++; ans[4]++;}
    else if(tens<4) ans[2]+=tens;
    else{ans[3]++; ans[2]+=(tens-5);}
    ans[4]+=hundreds;
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int d; cin >> d;
    for(int i=1; i<=d; i++) calc(i);
    for(auto x : ans) cout << x << " ";

    return 0;
}
