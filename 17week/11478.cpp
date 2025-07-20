#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    cin>>s;
    set<string> ans;
    
    for(int i=0;i<s.size();i++)
    {
        string str1 = "";
        for(int j=i;j<s.size();j++)
        {
            str1 +=s[j];
            ans.insert(str1);
        }
    }
    cout << ans.size();

}