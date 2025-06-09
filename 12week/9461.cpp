//12week / BOJ9461.파도반 수열 / 실버3 / DP / 시간 0ms / 메모리 2020KB


#include <iostream>

using namespace std;

int t,n;
long long p[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    
    for(int i = 6;i <= 100;i++) p[i] = p[i-1] + p[i-5];
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << p[n] << "\n";
        
    }
}