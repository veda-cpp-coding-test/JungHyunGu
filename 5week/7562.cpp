#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int t;
int l;

int board[301][301];
int dist[301][301];

void bfs(int x1, int y1){
    queue<pair<int,int>>q;
    q.push({x1,y1});
    dist[x1][y1] = 0; 
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i= 0;i<8;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(0<=nx && nx<l && 0<=ny && ny<l)
            {
                if (dist[nx][ny]==-1)
                {
                    dist[nx][ny] = dist[x][y]+1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

}


int main()
{
    cin>>t;

    while(t--)
    {
        //fill(dist[l],dist[l]+m,-1);
        memset(dist, -1, sizeof(dist));
        int x1,x2,y1,y2;
        cin>>l;
        cin>>x1>>y1;
        cin>>x2>>y2;
        
        bfs(x1,y1);
        cout << dist[x2][y2]<<'\n';
    }
}