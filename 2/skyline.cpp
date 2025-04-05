#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int ans[256]={0};
    for(int i=0; i<n; i++){
        int l, h, r;
        cin >> l >> h >> r;
        for(int j=l; j<r; j++) if(ans[j]<h) ans[j] = h;
    } int prev = 0;
    for(int i=1; i<256; i++){
        if(ans[i]!=prev){
            cout << i << " " << ans[i] << " ";
            prev = ans[i];
        }
    }

    return 0;
}
