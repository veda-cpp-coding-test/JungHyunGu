#include <iostream>

using namespace std;

int e,s,m;

//15 28 19

int main(){

    cin >> e >> s >> m;
    e--;
    s--;
    m--;
    for(int i = 0;; i++){
        if(i % 15 == e && i % 28 == s && i % 19 == m){
            cout << i + 1 ;
            return 0;
        }
    }



}