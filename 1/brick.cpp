#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
	int n, m; cin >> n >> m;
	char table[n][m+1]; int bricks[m], fblocks[m];
	for(int i=0; i<n; i++) scanf(" %s", table[i]);
	for(int i=0; i<m; i++){
		cin >> bricks[i];
		fblocks[i] = -1;
	}
	for(int i=0; i<m; i++) for(int j=0; j<n; j++){
		if(table[j][i]=='O'){
			fblocks[i] = j;
			break;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(table[i][j]=='O') cout << 'O';
			else if(i>=fblocks[j]-bricks[j] && i<fblocks[j]) cout << '#';
			else if(fblocks[j] == -1 && i>=n-bricks[j]) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
	
	return 0;
}
