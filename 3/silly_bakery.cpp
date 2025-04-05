#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, ip; cin >> n; float cakew=0;
	for(int i=0; i<n; i++) for(int j=0; j<5; j++){
		cin >> ip;
		if(j==0) cakew+=ip;
		else if(j==1) cakew+=ip*0.75;
		else if(j==2) cakew+=ip*0.5;
		else if(j==3) cakew+=ip*0.25;
		else if(j==4) cakew+=ip*0.125;
	}
	cout << ceil(cakew);
	
	return 0;
}
