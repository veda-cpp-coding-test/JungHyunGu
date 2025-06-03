//11week / BOJ11652.카드 / 실버4 / 정렬2 / 시간 104ms / 메모리 2800KB


#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
long long a[100'005];
int main()
{
    cin >>n ;
    for(int i = 0; i <n; i++) cin >> a[i];
    sort(a,a+n);
    int cnt = 0, max_count = 0;
    long long max_val = -(111LL << 62) - 1;
    for(int i = 0;i<n;i++){
        if(i==0 || a[i-1]== a[i]) cnt++;
        else {
            if(cnt>max_count){
                max_count = cnt;
                max_val = a[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > max_count) max_val = a[n-1];
    cout << max_val;
}