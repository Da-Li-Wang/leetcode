// https://www.acwing.com/problem/content/189/

#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> up,down;
void dfs(int u, int su, int sd, vector<int> &arr)
{
    if(su + sd >= ans) return;
    if(u == n)
    {
        ans = su + sd;
        return;
    }

    //将当前树放到上升子序列中
    int k = 0;
    while(k < su && up[k] >= arr[u]) k++;
    int temp = up[k];
    up[k] = arr[u];
    if(k < su) dfs(u+1, su, sd, arr);
    else dfs(u+1, su+1, sd, arr);
    up[k] = temp;
    //将当前树放到下降子序列中
     k = 0;
    while(k < sd && down[k] <= arr[u]) k++;
    temp = down[k];
    down[k] = arr[u];
    if(k < sd) dfs(u+1, su, sd, arr);
    else dfs(u+1, su, sd+1, arr);
    down[k] = temp;
}


int main()
{
    while (cin >> n, n)
    {
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr[i] = temp;
        }

        up = vector<int>(n);
        down = up;
        ans = n;
        dfs(0, 0, 0, arr);
        
        cout << ans <<endl;
    }
    return 0;
    
}