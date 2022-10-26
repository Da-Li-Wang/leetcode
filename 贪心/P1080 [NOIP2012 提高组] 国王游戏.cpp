#include <iostream>
#include <algorithm>
#include <vector>

struct king
{
    int l, r;
};

bool cmp(king a, king b)
{
    return a.l * a.r < b.l * b.r;
}

//高精计算

using namespace std;

vector <int> mul(vector<int>a, int b)
{
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size(); i++)
    {
        t += a[i]*b;
        c.push_back(t%10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10; 
    }
    return c;
}

vector<int> div(vector<int>a, int b)
{
    vector<int> c;
    bool is_first = true;
    for(int i = a.size() - 1, t = 0; i >= 0; i--)
    {
        t = t*10 + a[i];
        int x = t / b;
        if(!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> maxv(vector<int> a, vector<int> b)
{
    if(a.size() > b.size()) return a;
    if(a.size() < b.size()) return b;
    if(vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;
    return b;
}
int main()
{
    int n;
    cin >> n;
    vector<king> record(n+1);
    

    for(int i = 0; i <= n; i++)
    {
        cin >> record[i].l >> record[i].r;
    }

    sort(record.begin()+1, record.end(), cmp);
    
    //cout << record[n].l << endl << record[n].r;
    
    vector<int> sumw(1, 1), ans(1, 0);
    for(int i = 0; i <= n; i++)
    {
        if(i)ans = maxv(ans ,div(sumw, record[i].r));
        sumw =  mul(sumw, record[i].l);
    } 
    
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i];
    return 0; 

}