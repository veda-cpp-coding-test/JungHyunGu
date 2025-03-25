#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input[9];
    int i, total=0,idx=0;
    int answer[7];
    for(i=0;i<9;i++)
    {
        cin>>input[i];
        total+=input[i];
    }

    for(i = 0;i<9;i++)
    {
        for (int j = i+1;j<9;j++)
        {
            if (total - input[i] - input[j]==100)
            {
                for (int k = 0; k<9;k++)
                {
                    if(k!=i&&k!=j)
                    {
                        answer[idx++] = input[k];
                        
                    }
                }
                sort(answer, answer + 7);

                for (int k = 0; k < 7; k++) {
                    cout << answer[k] << "\n";
                }
                return 0;
            }
        }
        
    }
                
    return 0;

}



