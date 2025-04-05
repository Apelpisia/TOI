#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll getNum(string f, string s, string t){
    if(s=="|_|"){
        if(t=="  |") return 4;
        if(t=="|_|") return 8;
        return 9;
    } else if(s=="  |"){
        if(f=="   ") return 1;
        return 7;
    } else if(s==" _|"){
        if(t=="|_ ") return 2;
        return 3;
    } else if(s=="|_ "){
        if(t==" _|") return 5;
        else return 6;
    } return 0;
}

ll findNum(string fst, string sec, string trd, int dg){
    ll ans=0; int idcheck=0;
    string checkfst, checksec, checktrd;
    while(dg!=0){
        checkfst = fst.substr(idcheck, 3);
        checksec = sec.substr(idcheck, 3);
        checktrd = trd.substr(idcheck, 3);
        ans+=(getNum(checkfst, checksec, checktrd)*pow(10,dg-1));
        idcheck+=4; dg--;
    } return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n1, n2; string num[6]; cin >> n1 >> n2;
    cin.ignore();
    for(int i=0; i<6; i++) getline(cin, num[i]);
    cout << findNum(num[0], num[1], num[2], n1) + findNum(num[3], num[4], num[5], n2);

    return 0;
}
