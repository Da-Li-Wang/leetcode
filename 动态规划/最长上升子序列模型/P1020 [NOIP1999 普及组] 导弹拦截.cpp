#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int temp;
    while (cin >> temp)
    {
        arr.push_back(temp);
    }

    int n = arr.size(), ans1 = 0;
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] >= arr[i]) dp[i] = max(dp[j]+1, dp[i]);
        }
        ans1 = max(ans1, dp[i]);
    }

    cout << ans1 << endl;

    int ans2 = 0;
    vector<int> greedy(n+1);
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        while (k < ans2 && greedy[k] < arr[i]) 
        {
            k++;
        }
        greedy[k] = arr[i];
        if(k >= ans2) ans2++;   
    }

    cout << ans2 << endl;
    return 0;
}