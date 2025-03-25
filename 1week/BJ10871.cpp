#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int i,n,x,a[10000];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n>>x;
    for(i=0;i<n;i++) cin >>a[i];
    for(i=0;i<n;i++) if (a[i]<x) cout << a[i] << " ";
}