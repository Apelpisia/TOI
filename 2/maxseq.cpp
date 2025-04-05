#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
  int n; cin >> n;
  int seq[n]; for(int i=0; i<n; i++) cin >> seq[i];
  int best = INT_MIN, idstart, idend;
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=i; j<n; j++){
      sum+=seq[j];
      if(sum>best){
        best = sum;
        idstart = i;
        idend = j;
      }
    }
  }
  if(best<=0) cout << "Empty sequence";
  else{
    for(int i=idstart; i<=idend; i++) cout << seq[i] << " ";
    cout << "\n" << best;
  }

  return 0;
}
