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

    //Ŀ�� ���� ������ ����
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

    //left�� �ִ� �͵��� right�� �ű�
    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    
    //right�� ���ʷ� ���
    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}