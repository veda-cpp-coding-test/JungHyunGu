#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;  

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> n;

    vector<int> prime;
    int start = 0, end = 0, sum = 0, answer = 0;

    if(n == 1) {
        cout << "0";
        return 0;
    }

    int arr[n + 1];

    fill(arr, arr + n + 1, true);
    arr[1] = false;

    for(int i = 2 ; i <= sqrt(n) ; i++) {
        if(!arr[i]) continue;
        for(int j = i * i ; j <= n ; j+= i) arr[j] = false;
    }

    for(int i = 2 ; i <= n ; i++) if(arr[i]) prime.push_back(i);

    while(end <= prime.size()) {
        if(sum < n) {
            sum += prime[end];
            end++;
        }
        else if(sum >= n) {
            sum -= prime[start];
            start++;
        }
        if(sum == n) answer++;
    }

    cout << answer;

    return 0;
}