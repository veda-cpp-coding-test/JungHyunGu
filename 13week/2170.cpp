#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second

int n, x, y;

vector<pair<int, int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i = 0; i <n; i++){
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end());
    int answer = 0;
    int start = v[0].X;
    int end = v[0].Y;

    for(int i = 1; i < n; i++){
        int a = v[i].X;
        int b = v[i].Y;
        if(end>=a) { end = max(end,b); }
        else{ 
            answer += end - start; 
            end = b; 
            start = a; 
        }
    }
    answer += end - start; // 마지막 구간
    cout << answer;
}