#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cnt=0; cin >> n;
    int f[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> f[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i-2>=0 && f[i][j]==f[i-2][j] && f[i][j]==f[i-1][j]) || (i+2<n && f[i][j]==f[i+2][j] && f[i][j]==f[i+1][j]) ||
               (j-2>=0 && f[i][j-2]==f[i][j] && f[i][j]==f[i][j-1]) || (j+2<n && f[i][j]==f[i][j+2] && f[i][j]==f[i][j+1]) ||
               (i-1>=0 && j-1>=0 && f[i][j]==f[i-1][j-1] && (f[i][j]==f[i-1][j] || f[i][j]==f[i][j-1])) ||
               (i-1>=0 && j+1<n && f[i][j]==f[i-1][j+1] && (f[i][j]==f[i-1][j] || f[i][j]==f[i][j+1])) ||
               (i+1<n && j+1<n && f[i][j]==f[i+1][j+1] && (f[i][j]==f[i+1][j] || f[i][j]==f[i][j-1])) ||
               (i+1<n && j-1>=0 && f[i][j]==f[i+1][j-1] && (f[i][j]==f[i+1][j] || f[i][j]==f[i][j-1])) ||
               (i+1<n && i-1>=0 && f[i+1][j]==f[i-1][j]) || (j+1<n && j-1>=0 && f[i][j-1]==f[i][j+1])) continue;
            int check=0;
            if(i-1>=0 && f[i][j]==f[i-1][j]) check++;
            if(i+1<n && f[i][j]==f[i+1][j]) check++;
            if(j-1>=0 && f[i][j]==f[i][j-1]) check++;
            if(j+1<n && f[i][j]==f[i][j+1]) check++;
            if(check==2) cnt++;
        }
    } cout << cnt;

    return 0;
}
