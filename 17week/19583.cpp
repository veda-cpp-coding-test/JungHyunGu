#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> nicknames;
string s, e, q, time, nickname;
int answer;

int main()
{
    ios::sync_with_stdio(0), 
    cin.tie(0);

    cin >> s >> e >> q;

    while (cin >> time >> nickname)
    {
        if (time <= s) 
        {
            nicknames[nickname] = 1;
        }
        else if (time >= e && time <= q) 
        {
            if (nicknames[nickname] == 1)
            {
                nicknames[nickname] = 2; 
                ++answer;
            }
        }
    }

    cout << answer;
    return 0;
}