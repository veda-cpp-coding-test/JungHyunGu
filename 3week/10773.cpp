#include<iostream>
#include<stack>


using namespace std;

int main()
{
    stack<int> s;
    int k, num,answer=0;
    cin>>k;
    for(int i=0; i<k;i++)
    {
        cin>>num;
        if(num == 0) s.pop();
        else s.push(num);
    }
    int stack_size = s.size();

    for(int i=0;i<stack_size;i++)
    {
        answer+=s.top();
        s.pop();
    }


    cout << answer;
    return 0;
}