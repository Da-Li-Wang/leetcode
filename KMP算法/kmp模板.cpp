//P3375 【模板】KMP字符串匹配
//https://www.luogu.com.cn/problem/P3375

#include <iostream>

using namespace std;

const int N = 1000010, M = 1000010;
char p[N], s[M];
int ne[N];

int main()
{
    cin >> s+1 >> p+1;
    int n = strlen(p+1), m = strlen(s+1);

    //求next的过程
    for(int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }

    //kmp匹配过程
    for(int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n)
        {
            cout << i - n + 1 << endl;
            j = ne[j];
        }
    }
    
    //next数组
    for(int i = 1; i <= n; i++) cout << ne[i] << " ";
    return 0;
}