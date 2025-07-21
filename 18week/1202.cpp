#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

#define X first
#define Y second

int n,k;
pair<int, int> jewel[300'003];
multiset<int> bag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> jewel[i].Y >> jewel[i].X;
    }

    sort(jewel, jewel+n);

    for(int i = 0 ; i < k; i++){
        int c;
        cin >> c;
        bag.insert(c);
    }


    long long answer = 0 ;

    for(int i = n-1; i >= 0; i--){
        int m,v;
        tie(v,m) = jewel[i];      // x,y 입력 거꾸로
        auto it = bag.lower_bound(m);
        if(it == bag.end()) continue;

        answer += v;
        bag.erase(it);
    }


    cout << answer;

}