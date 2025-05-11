#include <iostream>
#include <algorithm>

using namespace std;

int n, answer = 0, eggs[9], power[9];

void func(int idx)
{
    if (idx > n+1) return; // 현재 계란 범위 넘어가면 종료
    for(int i = 1;i<=n;i++){
        if(eggs[idx]<=0) func(idx + 1); // 계란이 이미 깨져있으면 다음 계란으로 
        else if (eggs[i]<=0 || idx == i) continue;// 깨져있거나 들고 있는 계란일때 다음 계란으로
    
        else{ // 문제 없으면 내구도 차감, 다음 계란으로 ㄱㄱ
            eggs[idx] -= power[i];
            eggs[i] -= power[idx];
            func(idx + 1); 
            eggs[idx] += power[i];
            eggs[i] += power[idx];
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){ // 백트래킹 끝날때마다 깨진거 세어야함
        if(eggs[i]<=0) cnt++;
        answer = max(answer,cnt);
    }
}


int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++) cin >> eggs[i] >> power[i];
    func(1);
    cout<<answer;
}