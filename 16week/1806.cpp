#include<iostream>

using namespace std;

int n,s,total;
int a[100'005];
int mn = 0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i = 0; i < n; i++) cin >> a[i];
    total = a[0];
    int en = 0;
    for (int st = 0; st < n; st++){
        while(en < n && total < s){
            en++;
            if(en != n) total += a[en];
        }
        if (en == n) break;
        mn = min(mn, en - st + 1);
        total -= a[st];

    }
    if(mn == 0x7fffffff) mn = 0;
    cout << mn;

}