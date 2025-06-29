#include <iostream>

using namespace std;
int n,k;
bool isprime[1005];

int main(){

    cin>>n>>k;
    int answer = 0;
    for(int i = 2; i<=n;i++){
        if(isprime[i] == true) continue;
        for (int j = i; j <= n; j += i) {
			//지워지지 않았을 때
			if (isprime[j] == false) {
				isprime[j] = true;
				answer++;
				if (answer == k) {
					cout << j << "\n";
					return 0; //종료
				}
			}
		}
    }
}