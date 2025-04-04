#include <iostream>
#include <algorithm>

using namespace std;
int a[1000001] = {};
bool occur[2000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i,x,answer = 0;
    
    cin >> n;
    for(i = 0;i<n;i++) cin>>a[i];
    cin >> x;

    for(i = 0; i<n; i++)
    {
        if(x-a[i]>0&&occur[x-a[i]]) answer ++;
        occur[a[i]] = true;

    }
    cout<<answer;

    return 0;

}