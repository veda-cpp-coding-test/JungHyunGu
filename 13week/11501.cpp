#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    for(int i = 0; i < t; i++){
        cin>>n;
        vector<int>v;
        for(int j = 0; j <n; j++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        int mx = -1;
        long long answer = 0;
        for(int k = n - 1; k >= 0; k--){
            mx = max(mx, v[k]);
            answer += mx-v[k];
        }
        cout << answer << "\n";
    }
    
}