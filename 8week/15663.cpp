#include <iostream>
#include <algorithm>

using namespace std;

int n,m, input[10], answer[10];
bool isUsed[10];

void func(int s){
    if(s == m){ // m개의 수를 모두 선택한 경우
        for(int i = 0; i<m;i++) cout << answer[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for(int i = 0; i<n; i++){
        // 아직 사용하지 않았고, 이전에 같은 값을 사용하지 않은 경우에만 선택
        if(!isUsed[i] && tmp != input[i]){
            answer[s] = input[i];
            tmp = input[i]; // 중복방지
            isUsed[i] = 1;
            func(s+1);
            isUsed[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i= 0; i<n; i++) cin >> input[i];
    sort(input,input+n);
    func(0);
}