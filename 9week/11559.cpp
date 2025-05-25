//9week / BOJ11559.Puyo Puyo / 골드4 / 시뮬레이션 / 시간 0ms / 메모리 2028KB


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define X first
#define Y second
using namespace std;

int answer;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[12][6];
bool visit[6][12]; 

bool bfs(int x, int y, char c){ //부시는지
    queue<pair<int,int>> q;
    vector<pair<int,int>> v; //size가 4 이상되면 터트리고 아니면 초기화한다.
    memset(visit, false, sizeof(visit));
    q.push({x,y});
    v.push_back({x,y});
    visit[x][y] = 1;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= 6 || ny >= 12 || visit[nx][ny]) continue;
            if(board[ny][nx] == c && !visit[nx][ny]){
                q.push({nx,ny});
                v.push_back({nx,ny});
                visit[nx][ny] = 1;
            }
        }
    }

    if(v.size() >= 4){
        int vs = v.size();
        for(int i=0; i< vs; i++){
            board[v[i].Y][v[i].X] = '.';
        }
        return true;
    }

    return false; //못부심
}

void down(){
    for(int i = 0; i< 6; i++){ 
        queue<char> q;
        for(int j =12-1; j >= 0; j--){ // 아래부터
            if(board[j][i] != '.'){
                q.push(board[j][i]);
            }
        }
        int q_size = q.size();
        for(int j=12-1; j >= 12-q_size; j--){
            board[j][i] = q.front(); q.pop();
        }
        for(int j =12-q_size-1; j >= 0; j--){
            board[j][i] = '.';
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<12; i++){
        string s;
        cin >> s;
        for(int j=0; j<6; j++){
            board[i][j] = s[j];
        }
    }
    
    while(1){ 
        int flag = 0;
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(board[i][j] != '.'){
                    if(bfs(j,i,board[i][j])){ 
                        flag++;
                    }
                }
            }
        }

        if(flag == 0) break;
        else{
            //하나라도 터트렸으면 다시 돌림
            answer++;
            down();
        }
    }
    
    if(answer) cout << answer;
    else if(!answer) cout << '0';
}
