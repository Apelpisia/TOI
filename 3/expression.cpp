#include <bits/stdc++.h>

using namespace std;

string eq;
int tc;
queue<int> q;
stack<int> st;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> eq >> tc;
    while(tc--){
        int ip; cin >> ip;
        while(ip!=0){
            q.push(ip);
            st.push(ip);
            cin >> ip;
        }
        string now = eq;
        while(!q.empty()){
            string temp = "";
            int tofind = q.front(), cnt = 0, par = 0, eqlen = now.length();
            q.pop();
            if(now=="") continue;
            if(eqlen==1){
                if(tofind==1) continue;
                else{
                    now = "";
                    continue;
                }
            }
            char lprior = '(';
            for(int i=0; i<eqlen; i++){
                if(now[i]==')'){par--; continue;}
                if(now[i]=='(') par++;
                if(par>0) continue;
                if(now[i]=='+') lprior = '+';
                else if(now[i]=='*' && lprior!='+') lprior = '*';
                else if(now[i]=='^' && lprior!='+' && lprior!='*') lprior = '^';
            }
            if(lprior=='('){
                if(tofind==1){
                    now.pop_back();
                    now.erase(now.begin());
                    continue;
                } else{
                    now = "";
                    continue;
                }
            }
            par = 0;
            for(int i=0; i<eqlen; i++){
                if(now[i]=='('){
                    par++;
                    temp+=now[i];
                    continue;
                }
                if(now[i]==')'){
                    par--;
                    temp+=now[i];
                    continue;
                }
                if(par>0){
                    temp+=now[i];
                    continue;
                }
                if(now[i]==lprior) cnt++;
                if(cnt==tofind){
                    now = temp;
                    break;
                }
                temp+=now[i];
                if(now[i]==lprior) temp = "";
            }
            if(cnt==tofind-1) now = temp;
            else if(cnt<tofind) now = "";
        }
        int stsz = st.size();
        while(!st.empty()){
            cout << "op(" << st.top() << ',';
            st.pop();
        } cout << 'p';
        while(stsz--) cout << ')';
        cout << '=';
        if(now=="") cout << "null\n";
        else cout << now << "\n";
    }

    return 0;
}
