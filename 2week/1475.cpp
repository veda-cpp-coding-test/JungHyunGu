#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,cnt[10]={}, result = 0;
    
    cin>>N;
    
    while(N)
    {   
        cnt[N%10]++;
        N /=10;
    }

    for (int i=0;i<10;i++)
    {
        if(i==6||i==9)continue;
        result = max(result, cnt[i]);
    }
    //만약 6과 9가 함께 카운팅해서 올라가면
    result = max(result, (cnt[6]+cnt[9]+1)/2);
    cout<<result;
    return 0;
}