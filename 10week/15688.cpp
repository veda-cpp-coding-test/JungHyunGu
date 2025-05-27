//10week / BOJ15688.수 정렬하기5 / 실버5 / 정렬1 / 시간 4256ms / 메모리 8292KB


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector <int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>n;
    for(int i = 0; i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<v.size();i++) cout << v[i] << "\n";
}