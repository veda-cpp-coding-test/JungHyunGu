//12week / BOJ14501.퇴사 / 실버3 / DP / 시간 0ms / 메모리 2020KB


#include <iostream>
#include <algorithm>

using namespace std;

int n, t[16], p[16], d[16];

int main(){
    cin>>n;
    for(int i = 1; i <=n;i++) cin>>t[i] >> p[i];
    for(int i = 1; i <=n;i++) {
        // 상담을 선택하는 경우우
        if(i+t[i]<= n+1) d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
        // 상담 안하고 넘길때
        d[i+1] = max(d[i+1], d[i]);
    }
    cout << *max_element(d,d+n+2);
}