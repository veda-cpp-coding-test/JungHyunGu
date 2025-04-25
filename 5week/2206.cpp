#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

string board[1002];
#define X first
#define Y second
int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist1[1002][1002]; // 벽을 부수지 않은 상태에서의 거리
int dist2[1002][1002]; // 벽을 한 번 부순 상태에서의 거리


int main()
{   
    cin>>n>>m;
    for(int i = 0;i<n;i++) 
    {   cin>>board[i];
        fill(dist1[i],dist1[i]+m,-1);
        fill(dist2[i],dist2[i]+m,-1);
    }
    

    queue<tuple<int,int,bool>> q;
    q.push({0, 0, false});
    dist1[0][0] = 1;

    while(!q.empty())
    {
        auto [x,y,broken] = q.front(); q.pop();
        for(int dir = 0; dir<4;dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (board[nx][ny] == '0')
            {
                if (!broken && dist1[nx][ny] == -1)
                {
                    dist1[nx][ny] = dist1[x][y] + 1;
                    q.push({nx, ny, false});
                }
                else if (broken && dist2[nx][ny] == -1)
                {
                    dist2[nx][ny] = dist2[x][y] + 1;
                    q.push({nx, ny, true});
                }
            }
            else if (board[nx][ny] == '1')
            {
                if (!broken && dist2[nx][ny] == -1)
                {
                    dist2[nx][ny] = dist1[x][y] + 1;
                    q.push({nx, ny, true});
                }
            }


        }
       
    }
    int ans1 = dist1[n - 1][m - 1];
    int ans2 = dist2[n - 1][m - 1];

    if (ans1 == -1 && ans2 == -1)
        cout << -1 << "\n";
    else if (ans1 == -1)
        cout << ans2 << "\n";
    else if (ans2 == -1)
        cout << ans1 << "\n";
    else
        cout << min(ans1, ans2) << "\n";

    return 0;


}