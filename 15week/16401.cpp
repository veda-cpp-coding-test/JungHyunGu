#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,input;

vector<int> v;

int main(){
    cin >> m >> n;
    int answer = 0;

    for(int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    int low = 1;
    int high = v[n-1];

    while(low <= high){
        int mid = (low + high) / 2;
        int count = 0;
        for(int  i = 0; i<n; i++) count += v[i]/mid;
        if(count <m) high = mid -1;
        else {
            answer = mid;
            low = mid + 1;
        }
    }

    cout << answer;
    
}