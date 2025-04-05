#include <bits/stdc++.h>

using namespace std;

bool isNugget(int n){
    if(n<6)return false;
    if(n%3==0 || n%20==0) return true;
    return isNugget(n-20);
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    if(n<6) cout << "no";
    else for(int i=6; i<=n; i++){
        if(isNugget(i)) cout << i << "\n";
    }

    return 0;
}
