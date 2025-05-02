#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,r;

vector<int> adj[1000001];
int visited[100001];
int ordered =1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>r;

    
    for(int i = 0;i<m;i++)
    {
        int start,end;
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    for(int i = 1;i<=n;i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }


    stack<int>s;
    s.push(r);
    



    while(!s.empty())
    {
        int cur = s.top();s.pop();
        // bool find = false;
        if(visited[cur]) continue;
        visited[cur]=ordered++;
        for(int i = adj[cur].size()-1; i>=0; i--)
        {
            int next = adj[cur][i];
            if(!visited[next])
            {
                s.push(next);
            }
        }
    }

    for(int i = 1; i<=n;i++) cout << visited[i] << "\n";
    
}

