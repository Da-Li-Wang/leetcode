#include <iostream>

using namespace std;

/*
int main()
{
    int n;
    cin >> n;
    int m = 1 << n;
    cout << endl;
    for(int i = 1; i < m; i++)
    {
        int count = 1, temp = i;
        while(temp)
        {
            if(temp & 1) cout << count << ' ';
            temp = temp >> 1;
            count++;
        }
        cout << endl;
    }

    return 0;
}
*/

int n;
const int M = 20;
bool status[M] = {false};
void dfs(int u)
{
    if(u > n)
    {
        for(int i = 0; i <= n; i++)
        {
            if(status[i]) cout << i << " ";
        }
        cout << endl;
    }

    dfs(u+1);
    status[u] = true;
    dfs(u+1);
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}

