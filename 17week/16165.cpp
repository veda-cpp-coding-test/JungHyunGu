#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    vector<string>::iterator iter;
    
    string gName;
    
    map<string, vector<string>> group;
    map<string, string> member;

    cin >> n;
    cin >> m;
    
    for (int i=0; i< n; i++) {
        int num;
        string name;
        vector<string> mem;
        cin >> gName >> num;

        for(int j=0; j< num; j++) {
            cin >> name;
            mem.push_back(name);
            member.insert(make_pair(name, gName));
        }
        sort(mem.begin(), mem.end());
        group.insert(make_pair(gName, mem));
    }
	
    for (int i=0; i<m; i++) {
        string s;
        int type;

        cin >> s >> type;
        if (type == 1) {
            cout << member[s] << endl;
        } else {
            for (iter = group[s].begin(); iter != group[s].end(); iter++) {
                cout << * iter << endl;
            }
        }
    }

    return 0;
}