#include <bits/stdc++.h>

using namespace std;

double tonum(string n){
    int op=0, p=0;
    for(int i=n.length()-1; i>=0; i--){
        op+=(int)(n[i]-48)*pow(10,p++);
    } return op;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout << setprecision(3) << fixed;
    string ip; double x=0, y=0;
    cin >> ip;
    while(ip!="*"){
        string cmd; double n;
        if(ip[ip.length()-2]>'A'){cmd=ip.substr(ip.length()-2, 2); n=tonum(ip.substr(0, ip.length()-2));}
        else{cmd=ip.substr(ip.length()-1, 1); n=tonum(ip.substr(0, ip.length()-1));}
        double nd=n*sqrt(2)/2;
        if(cmd=="N") y+=n;
        else if(cmd=="S") y-=n;
        else if(cmd=="W") x-=n;
        else if(cmd=="E") x+=n;
        else if(cmd=="NE"){
            x+=nd;
            y+=nd;
        } else if(cmd=="NW"){
            x-=nd;
            y+=nd;
        } else if(cmd=="SE"){
            x+=nd;
            y-=nd;
        } else if(cmd=="SW"){
            x-=nd;
            y-=nd;
        }
        cin >> ip;
    } cout << x << " " << y << "\n" << sqrt(pow(x, 2) + pow(y, 2));

    return 0;
}
