//10week / BOJ10814.나이순 정렬 / 실버5 / 정렬1 / 시간 100ms / 메모리 7904KB


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool compare(pair<int,string> a, pair<int,string> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin>> n;
    vector<pair<int,string>> v(n);

    for(int i = 0;i<n;i++) cin>>v[i].first >> v[i].second;

    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0;i<n;i++) cout<<v[i].first << " " << v[i].second << "\n";

}