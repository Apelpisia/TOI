#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

vector<int> wait; queue<int> ans; map<int, int> cls;

void E(int stu){
    bool alrq = false;
    if(wait.empty()) wait.push_back(stu);
    else{
        for(int i=wait.size()-1; i>=0; i--){
            if(cls[wait[i]]==cls[stu]){
                wait.insert(wait.begin()+i+1, stu);
                alrq = true; break;
            }
        } if(!alrq) wait.push_back(stu);
    }
}

void D(){
    ans.push(wait[0]);
    wait.erase(wait.begin());
}

int main(int argc, char** argv){
    int nc, ns; cin >> nc >> ns;
    for(int i=0; i<ns; i++){
        int c, s; cin >> c >> s;
        cls[s] = c;
    }

    char command; cin >> command;
    while(command!='X'){
        if(command=='E'){
            int ts;
            cin >> ts;
            E(ts);
        } else if(command=='D'){
            D();
        }
        cin  >> command;
    }

    if(ans.empty()) cout << "empty";
    else{
        while(!ans.empty()){
            cout << ans.front() << "\n";
            ans.pop();
        }
    }
    
    cout << 0;

    return 0;
}
