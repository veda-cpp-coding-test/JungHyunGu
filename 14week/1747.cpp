#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

long long n;

bool isPrime(int n){

    if (n<2) return false;
    
    for(int i = 2; i<= sqrt(n);i++){
        if (n%i==0) return false;
    }
    
    return true;
}

bool isPalindrome(string str){

    string front, back;
    front = str;
    reverse(str.begin(), str.end());
    back = str;

    if (front == back) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = n; ; i++){
        if(isPrime(i) && isPalindrome(to_string(i))) {
            cout << i;
            return 0;
        }
    }

}