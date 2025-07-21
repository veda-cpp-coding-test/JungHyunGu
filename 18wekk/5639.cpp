#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

void tree(int start, int end){
	if(start >= end) return;
	if(start == end-1){
		cout << v[start] << '\n';
		return;
	}
	int idx = start + 1;
	while(idx < end){
		if(v[start] < v[idx]) break;
		idx++;
	}
	tree(start+1, idx);
	tree(idx, end);
	cout << v[start] << '\n';
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin >> n){
		v.push_back(n);
	}
	tree(0, v.size());
	return 0;
}
