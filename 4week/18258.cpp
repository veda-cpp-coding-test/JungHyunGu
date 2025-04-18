#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    int x,n;
    queue <int>q;
    cin >> x;

    for(int i=0;i<x;i++)
    {
        cin>>cmd;
        if(cmd=="push") 
        {
            cin >> n;
            q.push(n);
        }
        else if(cmd=="pop")
        {
            if(q.size()==0) cout << -1 << "\n";
            else{
                cout<<q.front()<<"\n";
                q.pop();
            }
            
        }
        else if(cmd=="size")
        {
            cout << q.size() << "\n";
        }
        else if(cmd=="empty")
        {
            cout << q.empty() << "\n";
        }
        else if(cmd=="front")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
            }
            else cout << q.front() <<"\n";
        }
        else if(cmd=="back")
        {
            if(q.empty())
            {
                cout << -1 << "\n";
            }
            else cout << q.back() <<"\n";
        }
    }

}