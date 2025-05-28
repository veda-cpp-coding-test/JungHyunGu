// 10week / BOJ11651.좌표 정렬하기 2 / 실버5 / 정렬1 / 시간 104ms / 메모리 2808KB

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b )
{
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}


int main()
{
    
    int n;
    cin>>n;
    vector <pair<int,int>> v(n);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);
    for(int i = 0;i<n;i++) cout<< v[i].first << " " << v[i].second<<"\n";
}