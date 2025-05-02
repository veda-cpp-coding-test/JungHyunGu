#include <iostream>
#include <queue>
#include <stack>

using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1001][1001];
int visited[1001];
int n,m,v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>v;
    

    for(int i=0;i<m;i++)
    {
        int start, end;
        cin>>start >> end;
        board[start][end] = 1;
        board[end][start] = 1;
        
        
    }
    queue<int>q;
    stack<int>s;
    

    // DFS
    s.push(v);
    visited[v]= 1;
    cout << v << " ";

    while(!s.empty())
    {
        int cur = s.top();
        bool find = false;
        for(int i = 1;i<=n;i++)
        {
            if(board[cur][i]==1&&visited[i]==0)
            {
                s.push(i);
                visited[i] = 1;
                cout << i << " ";
                find = true;
                break;
            }
        }
        if(!find) s.pop();
        
    }


    cout << "\n";

    fill(visited, visited+n+1, 0);

    q.push(v);
    visited[v] = 1;
    cout << v << " ";

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i=1;i<=n;i++)
        {
            if (board[cur][i] == 1 && visited[i]==0)
            {
                q.push(i);
                visited[i] = 1;
                cout<< i << " ";
            }
        }
    }

}