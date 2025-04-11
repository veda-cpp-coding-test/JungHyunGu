#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, i, num;
    stack <pair<int,int>> s;

    cin >>N;

    for (i = 1;i<=N;i++)
    {
        cin>>num;
        while(!s.empty())
        {
            if(num < s.top().second)
            {
                cout<<s.top().first << " ";
                break;
            }
            s.pop();
        }
        if(s.empty())
        {
            cout << 0<< " ";
        }
        s.push(make_pair(i, num));
    }
    return 0;
}