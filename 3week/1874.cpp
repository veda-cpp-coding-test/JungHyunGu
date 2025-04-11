#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector <char> answer;
    stack <int> s;
    int n, i, a, cnt = 1;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        while(cnt<=a)
        {
            s.push(cnt);
            cnt+=1;
            answer.push_back('+');

        }
        if (s.top()==a)
        {
            s.pop();
            answer.push_back('-');

        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    for(i=0;i<answer.size();i++)
    {
        cout<<answer[i] << "\n";
    }

}
