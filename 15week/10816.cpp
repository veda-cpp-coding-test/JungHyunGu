#include <iostream>
#include <algorithm>

using namespace std;

int a[500'005];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << upper_bound(a, a + n, x) - lower_bound(a, a + n, x) << " ";
    }
}