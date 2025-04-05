#include <bits/stdc++.h>

using namespace std;

char brd[5][5]={0};
int score=0;

bool pop(int r, int c, int m, int n){
    bool popped=false;
    if(c-1>=0 && brd[r][c-1]==brd[r][c]){
        popped = true; brd[r][c-1] = '-'; score+=5;
    } if(r+1<m && brd[r+1][c]==brd[r][c]){
        popped = true; brd[r+1][c] = '-'; score+=5;
    } if(c+1<n && brd[r][c+1]==brd[r][c]){
        popped = true; brd[r][c+1] = '-'; score+=5;
    } if(popped){
        brd[r][c] = '-'; score+=5;
    } return popped;
}

void grav(int m, int n){
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n; j++){
            if(brd[i][j]<='Z' && brd[i][j]>='A' && brd[i+1][j]=='-'){
                char check='-'; int prev=i;
                while(check=='-' && prev<m){
                    swap(brd[prev][j], brd[prev+1][j]);
                    prev++; check = brd[prev+1][j];
                } if(pop(prev, j, m, n)) grav(m, n);
            }
        }
    }
}

void act(int m, int n, int r, int c, char cmd){
    if(!(brd[r][c]<='Z' && brd[r][c]>='A')){
            score-=5; return;
    }
    if(cmd=='R') if(c+1>n || brd[r][c+1]!='-'){
        score-=5; return;
    } else{
        swap(brd[r][c], brd[r][c+1]);
        if(r+1<=m && brd[r+1][c+1]!='-'){
            if(pop(r, c+1, m, n)) grav(m, n);
        }
    }
    else if(c==0 || brd[r][c-1]!='-'){score-=5; return;}
    else{
        swap(brd[r][c], brd[r][c-1]);
        if(r+1<=m && brd[r+1][c-1]!='-'){
            if(pop(r, c-1, m, n)) grav(m, n);
        }
    }
    grav(m, n);
}

int main(int argc, char** argv){
    int m, n, times; cin >> m >> n;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> brd[i][j];
    cin >> times; while(times--){
        int r, c; char cmd;
        cin >> r >> c >> cmd;
        act(m, n, r, c, cmd);
    } cout << score << "\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cout << brd[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
