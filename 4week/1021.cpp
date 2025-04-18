#include <iostream>
#include <deque>


using namespace std;

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);

    int N, M, left, right, answer = 0;
    cin >> N >> M;
    deque <int> dq;
    for(int i = 1;i<=N;i++) dq.push_back(i);
    while(M--){
        int num;
        cin >> num;
        for(int i = 0; i < int(dq.size());i++)
        {
            if(dq[i]==num)
            {   
                left = i;
                right = dq.size() - left;
                break;
            }
        }
        if(left<=right) // 왼쪽이 빠를경우
        {
            while(1)
            {
                if(dq.front() == num) break;
                dq.push_back(dq.front()); // 왼쪽이동
                dq.pop_front();
                answer++;
                
            }
            dq.pop_front();
        }
        else
        {
            answer++;
            while(1)
            {
                if(dq.back() == num) break;
                dq.push_front(dq.back()); // 오른쪽 이동
                dq.pop_back();
                answer++;
                
            }
            dq.pop_back();
        }
    }
    cout << answer;



}