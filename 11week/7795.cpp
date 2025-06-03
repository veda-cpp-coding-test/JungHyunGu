//11week / BOJ7795.먹을 것인가 먹힐 것인가 / 실버3 / 정렬2 / 시간 28ms / 메모리 2420KB


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
vector<int> a,b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;

    for(int i = 0; i<t; i++){
        cin>>n>>m;
        a = vector<int>(n);
        b = vector<int>(m);

        for(int i = 0;i<n;i++) cin>>a[i];
        for(int i = 0;i<m;i++) cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int answer = 0;
        for(int i = 0;i<n;i++) answer += upper_bound(b.begin(), b.end(), a[i]-1) - b.begin();

        cout << answer << "\n" ;
    }
}

