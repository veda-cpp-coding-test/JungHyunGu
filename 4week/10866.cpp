#include <iostream>
#include <deque>

using namespace std;

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    int x,n;
    deque <int>dq;
    cin >> x;

    for(int i=0;i<x;i++)
    {
        cin>>cmd;
        if(cmd=="push_front") 
        {
            cin >> n;
            dq.push_front(n);
        }
        else if(cmd=="pop_front")
        {
            if(dq.size()==0) cout << -1 << "\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
            
        }
        else if(cmd=="push_back") 
        {
            cin >> n;
            dq.push_back(n);
        }
        else if(cmd=="pop_back")
        {
            if(dq.size()==0) cout << -1 << "\n";
            else{
                cout<<dq.back()<<"\n";
                dq.pop_back();
            }
            
        }
        else if(cmd=="size")
        {
            cout << dq.size() << "\n";
        }
        else if(cmd=="empty")
        {
            cout << dq.empty() << "\n";
        }
        else if(cmd=="front")
        {
            if(dq.empty())
            {
                cout << -1 << "\n";
            }
            else cout << dq.front() <<"\n";
        }
        else if(cmd=="back")
        {
            if(dq.empty())
            {
                cout << -1 << "\n";
            }
            else cout << dq.back() <<"\n";
        }
    }

}