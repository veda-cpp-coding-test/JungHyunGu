//9week / BOJ14891.톱니바퀴 / 골드5 / 시뮬레이션 / 시간 0ms / 메모리 2024KB

#include <iostream>
#include <cstring>

using namespace std;
string gear[4];
int Rotate[4];
int k, g, r;
int mul = 1;
int answer = 0;

void rotate(){
    for(int i = 0; i< 4; i++) Rotate[i] = 0;
}

void move(int idx, int clock) {
	if (clock == 1)
		gear[idx] = gear[idx].substr(7) + gear[idx].substr(0, 7);
	else if(clock == -1)
		gear[idx] = gear[idx].substr(1, 7) + gear[idx].substr(0, 1);
}

void left_check(int idx, int clock) {
	if (idx <= 0) return;
	if (gear[idx][6] != gear[idx - 1][2]) {
		Rotate[idx - 1] = clock * -1;
		left_check(idx - 1, clock * -1);
	}
}

void right_check(int idx, int clock) {
	if (idx >= 3) return;
	if (gear[idx][2] != gear[idx + 1][6]) {
		Rotate[idx + 1] = clock * -1;
		right_check(idx + 1, clock * -1);
	}
}

void check(int idx, int clock) {
	Rotate[idx] = clock;
	left_check(idx, clock);
	right_check(idx, clock);

	for(int i = 0; i < 4; i++)
		move(i, Rotate[i]);
}


int main() {
	
	for (int i = 0; i < 4; i++) {
		cin >> gear[i];
	}
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> g >> r;
        rotate();
		check(g - 1, r);
	}
	
	for (int i = 0; i < 4; i++) {
		answer += (gear[i][0] - '0') * mul;
		mul *= 2;
	}
	
	cout << answer;
}