//BOJ1759 make password

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int L,C;
int visit[15][15];
char c[15];

void dfs(int start, string str, int vowels, int consonants)
{

    //종료조건
    if(str.size()==L){
        if(vowels>=1&&consonants>=2){
            cout << str <<"\n";
            return;
        }
    }

    for(int i = start; i < C;i++){
        if(c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' ) dfs(i+1, str + c[i], vowels+1, consonants);
        else dfs(i+1, str + c[i], vowels, consonants+1);
    }
}

int main()
{
    cin>>L>>C;
    for(int i = 0;i<C;i++) cin >> c[i];
    sort(c,c+C);
    dfs(0, "", 0 , 0);
}