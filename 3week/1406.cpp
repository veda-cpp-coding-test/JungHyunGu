#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string input;

    //커서 왼쪽 오른쪽 구분
    stack<char> left, right;
    
    cin>>input;
    for(int i=0;i<int(input.size());i++) left.push(input[i]);
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        char cmd;
        cin>>cmd;
        if(cmd=='L')
        {
            if(!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if(cmd=='D')
        {
            if(!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        
        else if(cmd=='B')
        {
            if(!left.empty())
            {
                left.pop();
            }
        }
        else if(cmd=='P')
        {
            char s;
            cin>>s;
            left.push(s);
        }
    }

    //left에 있는 것들을 right로 옮김
    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    
    //right를 차례로 출력
    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}