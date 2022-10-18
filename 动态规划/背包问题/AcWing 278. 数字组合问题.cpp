#include <iostream>
#include <cstring>
using namespace std;
const int N = 10010;
int f[N];
int main(){
    int size, target;
    cin >> size >> target;
    //memset(f, 0x3f, sizeof(f)); 属性是count！
    f[0] = 1;
    //vector<int> nums(size+1);
    for(int i = 1; i <= size; i++)
    {
        int v;
        cin >> v;
        for(int j = target; j >= v; j--)
        {
            f[j] = f[j-v] + f[j];
        }
    }
    cout << f[target];

    return 0;
}