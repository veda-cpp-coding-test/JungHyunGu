#include <iostream>
#include <vector>

using namespace std;


void div(int n, int x, int y);
int n, arr[128][128];
int white, blue;

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j<n;j++)
        {
            cin >> arr[i][j];
        }
    }
    div(n, 0 ,0);
    cout << white << "\n" << blue;
}


void div(int n, int x, int y)
{
    for(int i =x; i<x+n; i++)
    {
        for(int j = y; j<y+n; j++)
        {
            if(!arr[i][j] == arr[x][y]){
                div(n/2, x,y);
                div(n/2, x+n/2,y);
                div(n/2, x,y+n/2);
                div(n/2, x+n/2,y+n/2);
                return;
            }
        }
    }
    if(arr[x][y]) blue++;
    else white++;
}