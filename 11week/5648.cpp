//11week / BOJ5648.역원소 정렬 / 실버5 / 정렬2 / 시간 4ms / 메모리 2804KB


#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long a[100'005];

int main(){

    cin>>n;
    for(int i = 0;i<n;i++){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        a[i] = stol(str);
    }

    sort(a, a+n);
    for(int i = 0;i<n;i++) cout << a[i] << "\n";


}