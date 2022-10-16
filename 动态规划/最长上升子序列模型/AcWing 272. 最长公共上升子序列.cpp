#include <iostream>
#include <vector>

using namespace std;

//n^3 时间复杂度

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n+1), nums2(n+1);
    vector<vector<int>> record(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) cin >> nums1[i];
    for(int i = 1; i <= n; i++) cin >> nums2[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            record[i][j] = record[i-1][j];
            if(nums1[i] == nums2[j])
            {                
                record[i][j] = max(1, record[i][j]);
                for(int k = 1; k < j; k++)
                {
                    if(nums2[k] < nums2[j]) record[i][j] = max(record[i][j], record[i][k] + 1);
                }
                ans = max(ans, record[i][j]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

//n^2 时间复杂度 优化一层循环

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n+1), nums2(n+1);
    vector<vector<int>> record(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) cin >> nums1[i];
    for(int i = 1; i <= n; i++) cin >> nums2[i];
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int maxtemp = 1;        
        for(int j = 1; j <= n; j++)
        {
            record[i][j] = record[i-1][j];
            /*
            if(nums1[i] == nums2[j])
            {                
                for(int k = 1; k < j; k++)
                {
                    if(nums2[k] < nums2[j]) record[i][j] = max(record[i][j], record[i][k] + 1);
                }
                ans = max(ans, record[i][j]);
            }
            */
            if(nums1[i] == nums2[j]) record[i][j] = max(record[i][j], maxtemp);
            if(nums2[j] < nums1[i]) maxtemp = max(maxtemp, record[i][j] + 1);
            ans = max(ans, record[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
    
    
}