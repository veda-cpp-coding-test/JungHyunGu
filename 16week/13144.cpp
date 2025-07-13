#include <iostream>
#include <map>

using namespace std;

int n;
int arr[100'005];

int main(){

    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];

    int start = 0, end = 0;
    long long answer = 0;
    map<int, int> m;
    m[arr[start]] = 1;

    while(1){
        while(end < n -1 && m[arr[end + 1]] == 0){
            end++;
            m[arr[end]]++;
        }
        if(start >= n || end >= n )break;
        answer += end - start +1;
        m[arr[start]]--;
        start++;
    }

    cout << answer;
}