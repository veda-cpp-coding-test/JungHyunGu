//8week / BOJ13549.숨바꼭질 3 / BFS / 시간 12ms / 메모리 2900KB

#include <iostream>
#include <queue>
#include <algorithm>

int n,k;
bool visit[100'001];
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main()
{
    cin>>n>>k;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int answer = pq.top().first;
        int x = pq.top().second;

        pq.pop();
        // if(visit[x]) continue; // 중복 방지
        visit[x] = 1;

        if(x==k){ cout << answer; break; } // 도착 cout << answer
        // 0초 후 x*2 이동 -> 우선순위 가장 높음
        if(x*2<=100'000 && !visit[x*2]) pq.push(make_pair(answer,x*2)); 
        // 1초 후 x-1 이동
        if(x-1>=0 && !visit[x-1]) pq.push(make_pair(answer+1,x-1));
        // 1초 후 x+ 이동
        if(x+1<=100'000 && !visit[x+1]) pq.push(make_pair(answer+1,x+1));
        
    }
    return 0;
}