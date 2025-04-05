#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
    int m, n; cin >> m >> n;
    char brd[m][n]; for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> brd[i][j];
            if(brd[i][j]<'a') brd[i][j]+=32;
        }
    } int wc; cin >> wc;
    while(wc--){
        string w; cin >> w;
        int len=w.length();
        for(int i=0; i<len; i++) if(w[i]<'a') w[i]+=32;
        for(int i=0; i<m; i++) for(int j=0; j<n; j++){
            if(brd[i][j]==w[0]){
                if(i+1>=len){
                    string c="", cr="";
                    int temp = i;
                    for(int k=0; k<len; k++){
                        c = c+brd[temp][j];
                        cr = brd[temp--][j]+cr;
                    } if(w==c || w==cr){
                        cout << i << " " << j << "\n";
                        goto found;
                    } if(j+1>=len){
                        string c="", cr="";
                        int temp=i, temp2=j;
                        for(int k=0; k<len; k++){
                            c = c+brd[temp][temp2];
                            cr = brd[temp--][temp2--];
                        } if(w==c || w==cr){
                            cout << i << " " << j << "\n";
                            goto found;
                        }
                    } if(n-j+1>=len){
                        string c="", cr="";
                        int temp=i, temp2=j;
                        for(int k=0; k<len; k++){
                            c = c+brd[temp][temp2];
                            cr = brd[temp--][temp2++];
                        } if(w==c || w==cr){
                            cout << i << " " << j << "\n";
                            goto found;
                        }
                    }
                } if(m-i+1>=len){
                    string c="", cr="";
                    int temp = i;
                    for(int k=0; k<len; k++){
                        c = c+brd[temp][j];
                        cr = brd[temp++][j]+cr;
                    } if(w==c || w==cr){
                        cout << i << " " << j << "\n";
                        goto found;
                    } if(j+1>=len){
                        string c="", cr="";
                        int temp=i, temp2=j;
                        for(int k=0; k<len; k++){
                            c = c+brd[temp][temp2];
                            cr = brd[temp++][temp2--];
                        } if(w==c || w==cr){
                            cout << i << " " << j << "\n";
                            goto found;
                        }
                    } if(n-j+1>=len){
                        string c="", cr="";
                        int temp=i, temp2=j;
                        for(int k=0; k<len; k++){
                            c = c+brd[temp][temp2];
                            cr = brd[temp++][temp2++];
                        } if(w==c || w==cr){
                            cout << i << " " << j << "\n";
                            goto found;
                        }
                    }
                } if(j+1>=len){
                    string c="", cr="";
                    int temp = j;
                    for(int k=0; k<len; k++){
                        c = c+brd[i][temp];
                        cr = brd[i][temp--]+cr;
                    } if(w==c || w==cr){
                        cout << i << " " << j << "\n";
                        goto found;
                    }
                } if(n-j+1>=len){
                    string c="", cr="";
                    int temp = j;
                    for(int k=0; k<len; k++){
                        c = c+brd[i][temp];
                        cr = brd[i][temp++]+cr;
                    } if(w==c || w==cr){
                        cout << i << " " << j << "\n";
                        goto found;
                    }
                }
            }
        }
        found:;
    }
