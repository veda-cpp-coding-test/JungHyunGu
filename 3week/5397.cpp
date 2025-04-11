#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
using namespace std;

// '-' 백스페이스, <> 1 이동



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;

    while(n--){
        string input;
        cin >> input;
        stack <char> left, right;

        for(char ch : input)
        {
            if(ch=='<'){
                if(!left.empty())
                {
                    right.push(left.top());
                    left.pop();
                }    
            }
            else if (ch=='>')
            {
                if(!right.empty())
                {
                    left.push(right.top());
                    right.pop();
                }
            }
            else if (ch=='-')
            {
                if(!left.empty()) left.pop();
            }
            else left.push(ch);

        }
        while(!left.empty())
        {
            right.push(left.top());
            left.pop();
        }
        while(!right.empty())
        {
            cout<<right.top();
            right.pop();
        }
        cout << "\n";
    }
    
}