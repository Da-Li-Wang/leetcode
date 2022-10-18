#include <iostream>
#include <vector>

using namespace std;

const int L = 110;
int f[L][L];

int N, V, M;
int main(){
    cin >> N >> V >> M;
    int v, m, w;
    for(int i = 1; i <= N; i++){
        cin >> v >> m >> w;
        for(int j = V; j >= v; j--)
        {
            for(int q = M; q >= m; q--)
            {
                f[j][q] = max(f[j][q], f[j-v][q-m] + w);
            }
        }
    }

    cout << f[V][M];
    return 0;
}