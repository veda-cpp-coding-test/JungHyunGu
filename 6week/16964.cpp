#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;
int order[100001];
bool check[100001];
vector<int> v[100001];
vector<int> dfs_v;

void dfs(int x) {
    if(check[x]==true)
    {
        return ;
    }
    check[x] = true;
    dfs_v.push_back(x);
    for(auto i : v[x]){
        if(!check[i]) dfs(i);
    }

}

bool compare(int &a, int &b){
    return order[a] < order[b];
}

int main()
{
    cin>>n;
    for(int i = 0; i<n-1; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> v2(n+1);
    for( int i =1;i<=n;i++){
        cin>>v2[i];
        order[v2[i]] = i;
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end(), compare);
    }

    dfs_v.push_back(0);
    if(v2[1]==1) dfs(1);
    if(dfs_v == v2) cout << "1" << "\n";
    else cout << "0" << "\n";
    return 0;
}