#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <pair<int, int>> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i<n;i++){
        int x,y,z,a; 
        cin >> x >> y >> z >> a;
        // ex) 3월 1일 -> 301로 만듬
        int st = x * 100 + y;
        int en = z * 100 + a;

        v.push_back({st,en});
    }
    sort(v.begin(), v.end());

    int count = 1;
    //가까운 꽃 3월 1일로 초기화
    int cur_en = 301;
    //멀리 핀 꽃
    int end_en = 301;

    for(const auto& [st, en] : v){

        // 11월 30일 이후
        if(end_en>= 1201)break;

        //현재 꽃이 이전 꽃 마지막 지점보다 크면 갱신
        if(st > cur_en){
            cur_en = end_en;
            count++;
        }
        //갱신했는데도 크면 꽃 끊김
        if(st>cur_en) break;
        
        // 이전 꽃보다 멀리 있으면 갱신
        end_en = max(end_en, en);
    }
    if(end_en < 1201) cout << 0;
    else cout << count;

    return 0;

}