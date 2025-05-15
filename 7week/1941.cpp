#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0};

bool y_princess[25]; 
int answer = 0;

using namespace std;
string status[5]; 

void bfs() {
    queue<pair<int, int>> q;
    bool visited[5][5] = {}; 
    int doyeon = 0, cnt = 0; 

    // 선택된 7명 중 한 명을 시작점으로 BFS 시작
    for (int i = 0; i < 25; i++) {
        if (!y_princess[i]) {
            int x = i / 5;
            int y = i % 5;
            visited[x][y] = true;
            q.push({x, y});
            break; // 시작점은 하나만
        }
    }

    // BFS로 인접한 공주 탐색
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt++; // 연결된 공주 수 증가
        if (status[cur.first][cur.second] == 'Y') doyeon++; // Y면 카운트
        if (doyeon >= 4) return; // Y가 4명 이상이면 실패 (S가 4명 미만)

        // 4방향 탐색
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue; 
            if (visited[nx][ny]) continue;
            if (y_princess[nx * 5 + ny]) continue; 
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    // 7명 전부 연결되어 있고 Y가 3명 이하일 경우 정답 증가
    if (cnt == 7) answer++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> status[i];

    fill(y_princess + 7, y_princess + 25, true);


    do {
        bfs(); 
    } while (next_permutation(y_princess, y_princess + 25));

    cout << answer; 
}
