#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int w, h, n; cin >> w >> h >> n;
    int window[w]={0};
    while(n--){
        int x, a;
        cin >> x >> a;
        for(int i=0; i<a; i++){
            if(x<w)window[x++]++;
            else break;
        }
    } int ans1=0, ans2=0;
    for(int i=0; i<w; i++){
        if(window[i]==0) ans1+=h;
        else if(window[i]==1) ans2+=h;
    } cout << ans1 << " " << ans2;

    return 0;
}
