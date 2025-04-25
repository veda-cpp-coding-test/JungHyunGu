#include <iostream>
#include <deque>
#include <stack>
#include <string>


using namespace std;

int main()
{
    stack<int>s;
    int answer = 0;
    string str;

    cin>>str;
    for(int i =0;i<str.size();i++)
    {
        if(str[i]=='(' && str[i+1]==')')
        {
            answer += s.size();
            i++;
        }
        else if (str[i]=='(')
        {
            s.push(i);
        }
        else if(str[i]==')')
        {
            answer++;
            s.pop();
        }
    }
    cout<<answer;

}