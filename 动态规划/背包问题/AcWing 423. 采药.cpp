

#include <iostream>
#include <vector>

using namespace std;

const int N = 110;
int v[N],w[N];

int main(){
    int c,n;
    cin >> c >> n;

    vector<int> f(c+1);

    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j >= v[i]; j++)
        {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }

    cout << f[c];
    return 0; 
}