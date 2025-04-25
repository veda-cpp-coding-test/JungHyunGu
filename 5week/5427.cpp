#include <iostream>
#include <queue>

using namespace std;

string board[1002];

int t;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist1[1002][1002];
int dist2[1002][1002];


// '.': 빈 공간
// '#': 벽
// '@': 상근이의 시작 위치
// '*': 불
// 각 지도에 @의 개수는 하나이다.

int main()
{
    cin>>t;
    while(t--)
    {
        int w,h;
        cin>>w>>h;
        for(int i = 0;i<h;i++)
        {
            fill(dist1[i],dist1[i]+w,-1);
            fill(dist2[i],dist2[i]+w,-1);
        }

        for(int i = 0;i<h;i++) cin >> board[i];

        queue<pair<int,int>> q1; // 불
        queue<pair<int,int>> q2; // 상근

        for(int i = 0; i<h;i++) {
            for(int j = 0; j<w;j++)
            {
                if(board[i][j]=='*')
                {
                    q1.push({i,j});
                    dist1[i][j]=0;
                }
                if(board[i][j]=='@')
                {
                    q2.push({i,j});
                    dist2[i][j]=0;
                }
            }
        }

        //불

        while(!q1.empty())
        {
            auto cur = q1.front();q1.pop();
            for(int dir = 0; dir<4;dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=h || ny<0 || ny >= w) continue;
                if(dist1[nx][ny]>=0 || board[nx][ny]=='#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
                q1.push({nx,ny});
            }
        }


        bool escape = false;
        
        while(!q2.empty())
        {
            auto cur = q2.front();q2.pop();
            for(int dir = 0; dir<4;dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=h || ny<0 || ny >= w) 
                {
                    cout << dist2[cur.X][cur.Y]+1<<"\n";
                    escape = true;
                    break;
                }
                if(dist2[nx][ny]>=0 || board[nx][ny]=='#') continue;
                if(dist1[nx][ny]!= -1 && dist1[nx][ny]<= dist2[cur.X][cur.Y]+1) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                q2.push({nx,ny});
            }
            if (escape) break;
        }
        
        if(!escape){
        cout <<"IMPOSSIBLE"<<"\n";
        }
    }
    
}