#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,answer=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        stack <char> s;
        string word;
        cin>>word;
        for(int j = 0;j<int(word.length());j++)
        {
            if(s.empty()) s.push(word[j]);
            else{
                if(s.top()==word[j])
                {
                    s.pop();
                }
                else{
                    s.push(word[j]);
                }
            }
        }
        if(s.empty()) answer++;
    }
    cout<<answer;
}