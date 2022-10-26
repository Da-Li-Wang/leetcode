#include <iostream>
#include <algorithm>
#include <vector>

struct cow
{
    int w, s;
};

bool cmp(cow a, cow b)
{
    return a.w + a.s > b.w + b.s;
}

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<cow> record;
    for(int i = 0; i < n; i++)
    {
        cin >> record[i].w >> record[i].s;
    }

    sort(record.begin(), record.end(), cmp);

    int sumw = 0, ans = INT_MIN;
    for(int i = n-1; i >= 0; i--)
    {
        ans = max(ans ,sumw - record[i].s);
        sumw += record[i].w;
    } 
    
    cout << ans;
    return 0; 

}