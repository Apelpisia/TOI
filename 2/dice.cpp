#include <bits/stdc++.h>

using namespace std;

int rotateDice(string rotation);

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string rotation[n];
	for(int i=0; i<n; i++) cin >> rotation[i];
	for(int i=0; i<n; i++) cout << rotateDice(rotation[i]) << ' ';
	
	return 0;
}

int rotateDice(string rotation){
	int len = rotation.length(), dc[6] = {1,2,3,5,4,6};
	for(int i=0; i<len; i++){
		switch(rotation[i]){
		case 'F':
			swap(dc[0], dc[1]);
			swap(dc[0], dc[5]);
			swap(dc[0], dc[3]);
			break;
		case 'B':
			swap(dc[0], dc[3]);
			swap(dc[0], dc[5]);
			swap(dc[0], dc[1]);
			break;
		case 'L':
			swap(dc[0], dc[2]);
			swap(dc[0], dc[5]);
			swap(dc[0], dc[4]);
			break;
		case 'R':
			swap(dc[0], dc[4]);
			swap(dc[0], dc[5]);
			swap(dc[0], dc[2]);
			break;
		case 'C':
			swap(dc[1], dc[2]);
			swap(dc[1], dc[3]);
			swap(dc[1], dc[4]);
			break;
		case 'D':
			swap(dc[1], dc[4]);
			swap(dc[1], dc[3]);
			swap(dc[1], dc[2]);
			break;
		}
	}
	return dc[1];
}
