#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int r, start, cnt;
} command;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, row=0; cin >> n;
    command ip[n];
    for(int i=0; i<n; i++){
        int r, start, cnt;
        cin >> r >> start >> cnt;
        ip[i].r=r-1; ip[i].start=start-1; ip[i].cnt=cnt;
        if(row<r) row=r;
    } string base = "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo";
    string ans[row]; for(int i=0; i<row; i++) ans[i] = base;
    for(int i=0; i<n; i++){
        for(int j=ip[i].start; j<ip[i].start+ip[i].cnt && j<=70; j++){
            ans[ip[i].r][j] = 'x';
        }
    }
    for(int i=0; i<row; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
