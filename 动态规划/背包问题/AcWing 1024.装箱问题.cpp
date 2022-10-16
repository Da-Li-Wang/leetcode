#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int c, n;
    cin >> c >> n;
    vector<int> f(c+1);
    int v;    
    for(int i = 1; i <= n; i++)
    {
        cin >> v; 
        for(int j = c; j >= v; j--)
        {
            //if(f[j-v] + v <= c) f[j] = max(f[j], f[j-v] + v);
            f[j] = max(f[j], f[j-v] + v);
        }
    }

    cout << c - f[c];
    return 0;     
}