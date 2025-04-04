#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B,C, mul = 0;
    int d[10] = {};
    cin>> A >> B >> C;
    mul = A*B*C;
    while(mul>0)

    {
        d[mul%10]++;
        mul/=10;
    }

    for(int i =0;i<10;i++) cout<<d[i]<<"\n";
    return 0;
}