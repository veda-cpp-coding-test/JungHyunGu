//12week / BOJ10844.쉬운 계단 수 / 실버1 / DP / 시간 0ms / 메모리 2028KB


#include <iostream>

using namespace std;

int stairs = 1'000'000'000;
int n;
long long d[101][10]; 

int main() {
    cin >> n;

    // 초기 조건: 길이 1일 때
    for (int i = 1; i <= 9; i++) {
        d[1][i] = 1;
    }

    for (int i = 2; i<=n; i++){
        for (int j = 0; j <= 9; j++){
            // 1 이상일 때: 이전 자릿수의 숫자가 j-1인 경우에서 올 수 있음
            if(j>=1) d[i][j] += d[i-1][j-1];    
            // 8 이하일 때: 이전 자릿수의 숫자가 j+1인 경우에서 올 수 있음
            if(j<=8) d[i][j] += d[i-1][j+1];
            // 오버플로우 방지
            d[i][j] %=  stairs;
        }
    }

    long long answer = 0;
    for(int i = 0; i<=9;i++) answer = (answer + d[n][i]) % stairs;
    cout<<answer;
}