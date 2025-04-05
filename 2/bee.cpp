#include <iostream>

using namespace std;

int ans[3] = {1,1,0};

void calc(int y){
    for(int i=0; i<y; i++){
        int tb = ans[1], ts = ans[2];
        ans[1]++; ans[2] = tb; ans[1]+=ts;
    }
}

int main()
{
    int n; cin >> n;
    while(n!=-1){
        calc(n);
        cout << ans[1] << ' ' << ans[0]+ans[1]+ans[2] << endl;
        ans[0] = 1; ans[1] = 1; ans[2] = 0;
        cin >> n;
    }


    return 0;
}
