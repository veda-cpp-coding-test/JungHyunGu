#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll; 

ll n;
ll arr[5004];
ll answer[4];
ll ret = 1e18; 

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+n);
	for(int i=1; i<=n-2; i++){
		ll st = i+1;
		ll en = n;
		while(st < en){
			
			ll v = arr[i] + arr[st] + arr[en];
			
			if(abs(v) < ret){ // 이전에 구했던 합보다 0에 더 가까운지 확인
				
				ret = abs(v); //ret 갱신

				answer[1] = arr[i];
				answer[2] = arr[st];
				answer[3] = arr[en];
			}
			if(v < 0) st++; //합이 0보다 작을 경우 st를 오른쪽으로 한 칸 이동
			else en--; //합이 0보다 크거나 같은 경우 en를 왼쪽으로 한 칸 이동
		}
	}
	for(int i = 1; i< 4; i++) cout << answer[i] << " ";
	return 0;
}