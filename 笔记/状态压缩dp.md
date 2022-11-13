# 状态压缩dp

包括**两类** ： 
1. 棋盘式（基于连通性）
2. 集合
[toc]

##  1. 棋盘式（基于连通性）
### 1.1 P1896 [SCOI2005] 互不侵犯


#### 题目描述

在N×N的棋盘里面放K个国王，使他们互不攻击，共有多少种摆放方案。国王能攻击到它上下左右，以及左上左下右上右下八个方向上附近的各一个格子，共8个格子。

注：数据有加强（2018/4/25）

#### 输入格式

只有一行，包含两个数N，K （ 1 <=N <=9, 0 <= K <= N \* N）

#### 输出格式

所得的方案数

#### 样例 #1

#### 样例输入 #1

```
3 2
```

#### 样例输出 #1

```
16
```

#### 闫氏Dp分析法

![](../图库/微信截图_20221102114016.png)

#### 代码

``` cpp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;
int cnt[M];
vector<int> head[M];
LL f[N][K][M];

bool check(int state)//检查state是否合法
{
    for(int i = 0; i < n; i++)
    {
        if((state >> i & 1) && (state >> i+1 & 1))//条件一 每行内部不能相邻
            return false;
    }
    return true;
}

int count(int state)//计算状态内有多少个1
{
    int res = 0;
    for(int i = 0; i < n; i++) res += state >> i & 1;
    return res;
}

int main()
{
    cin >> n >> m;
    
    for(int i = 0; i < 1 << n; i++)
    {
        if(check(i))//将合法状态记录
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }

    for(int i = 0; i < state.size(); i++)
    {
        for(int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if((a & b) == 0 && check(a | b))
            {
                head[i].push_back(j);//state[i] 状态可以转移到 state[j] 状态
            }
        }
    }

    f[0][0][0] = 1;//初始状态 即正摆0行用了0个棋子状态是0的方案数为1
    for(int i = 1; i <= n + 1; i++)//多加一轮 便于输出
    {
        for(int j = 0; j <= m; j++)
        {
            for(int a = 0; a < state.size(); a++)
            {
                for(int b : head[a])
                {
                    int c = cnt[state[a]];
                    if(j >= c) f[i][j][a] += f[i-1][j-c][b];
                }
            }
        }
    }


    cout << f[n+1][m][0] << endl;

    return 0;

     
}

```



### 1.2 AcWing 327. 玉米田


#### 题目描述

农夫约翰的土地由 M×N 个小方格组成，现在他要在土地里种植玉米。

非常遗憾，部分土地是不育的，无法种植。

而且，相邻的土地不能同时种植玉米，也就是说种植玉米的所有方格之间都不会有公共边缘。

现在给定土地的大小，请你求出共有多少种种植方法。

土地上什么都不种也算一种方法。

#### 输入格式

第 1 行包含两个整数 M 和 N。

第 2..M+1 行：每行包含 N 个整数 0 或 1，用来描述整个土地的状况，1 表示该块土地肥沃，0 表示该块土地不育。


#### 输出格式

输出总种植方法对 10\^8 取模后的值。

#### 数据范围

1≤M,N≤12。

#### 样例 #1

#### 样例输入 #1

```
2 3
1 1 1
0 1 0
```

#### 样例输出 #1

```
9
```

#### 闫氏Dp分析法
![](../图库/微信截图_20221103115314.png)

#### 代码

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int n,m;
int g[N];//原有地图记录
vector<int> state;
vector<int> head[M];//可以从 M 状态开始转移的状态集合 
int f[N][M];

bool check(int state)
{
    for(int i = 0; i < m; i++)
    {
        if((state >> i & 1) && (state >> i+1 & 1)) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            g[i] += !t << j;//原有地图记录（原有1代表能播种，需转换为0，反之亦然）
        }
    }

    for(int i = 0; i < 1 << m; i++)
    {
        if(check(i)) state.push_back(i);//所有不相邻播种状态
    }

    for(int i = 0; i < state.size(); i++)
    {
        for(int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if((a & b) == 0)
                head[i].push_back(j);//所有不相邻播种状态
        }
    }

    f[0][0] = 1;
    for(int i = 1; i <= n+1; i++)
    {
        for(int a = 0; a < state.size(); a++)
        {
            for(int b : head[a])
            {
                if(g[i] & state[a]) continue;//贫瘠土地
                f[i][a] = (f[i][a] + f[i-1][b]) % mod;
            }
        }
    }

    cout << f[n+1][0] << endl;//多进行一轮

    return 0;
}

```


### 1.3[NOI2001] 炮兵阵地

#### 题目描述

司令部的将军们打算在 $N\times M$ 的网格地图上部署他们的炮兵部队。

一个 $N\times M$ 的地图由 $N$ 行 $M$ 列组成，地图的每一格可能是山地（用 $\texttt{H}$ 表示），也可能是平原（用 $\texttt{P}$ 表示），如下图。

在每一格平原地形上最多可以布置一支炮兵部队（山地上不能够部署炮兵部队）；一支炮兵部队在地图上的攻击范围如图中黑色区域所示：

 ![](https://cdn.luogu.com.cn/upload/pic/1881.png) 

如果在地图中的灰色所标识的平原上部署一支炮兵部队，则图中的黑色的网格表示它能够攻击到的区域：沿横向左右各两格，沿纵向上下各两格。

图上其它白色网格均攻击不到。从图上可见炮兵的攻击范围不受地形的影响。

现在，将军们规划如何部署炮兵部队，在防止误伤的前提下（保证任何两支炮兵部队之间不能互相攻击，即任何一支炮兵部队都不在其他支炮兵部队的攻击范围内），在整个地图区域内最多能够摆放多少我军的炮兵部队。

#### 输入格式

第一行包含两个由空格分割开的正整数，分别表示 $N$ 和 $M$。

接下来的 $N$ 行，每一行含有连续的 $M$ 个字符，按顺序表示地图中每一行的数据。

#### 输出格式

一行一个整数，表示最多能摆放的炮兵部队的数量。

#### 样例 #1

#### 样例输入 #1

```
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
```

#### 样例输出 #1

```
6
```

#### 提示

对于 $100\%$ 的数据，$N\le 100$，$M\le 10$，保证字符仅包含 `P` 与 `H`。

#### 闫氏dp分析法

![](../图库/微信截图_20221104113007.png)

#### 代码

``` cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11, M = 1 << 10;

int n, m;
int g[110];
vector<int> state,head[M];
int cnt[M];
int f[2][M][M];


bool check(int state)//判断合法状态
{
    for(int i = 0; i < m; i++)
    {
        if((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i+2 & 1)))//均不相邻
            return false;
    }
    return true;
}

int count (int state)//得到炮台个数
{
    int res = 0;
    for(int i = 0; i < m; i++) res += state >> i & 1;
    return res; 
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)//画地图
    {
        for(int j = 0; j < m; j++)
        {
            char c; 
            cin >> c;
            if(c == 'H') g[i] += 1 << j;
        }
    }

    for(int st = 0; st < 1 << m; ++st)//得到所有合法状态
    {
        if(check(st))
            state.push_back(st), cnt[st] = count(st);
    }

    for(int cur : state)
    {
        for(int pre : state)
        {
            if(!(cur & pre))//前后两行不并行
                head[cur].push_back(pre);
        }
    }

    for(int i = 1; i <= n+2; ++i)//得到前n+2行数据
    {
        for(int st : state)
        {
            if(!(g[i] & st))
            {
                for(int p1 : head[st])
                {
                    for(int p2 : head[p1])
                    {
                        if(!(st & p2))//隔行不并行
                        {
                            f[i & 1][st][p1] = max(f[i & 1][st][p1] , f[i-1 & 1][p1][p2] + cnt[st]);//滚动数组优化
                        }
                    }
                }
            }
        }
    }

    cout << f[n+2 &1][0][0];//输出
    return 0;
}
```

##  2. 集合

### 2.1 AcWing 91.最短Hamilton距离
给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。

Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

#### 输入格式
第一行输入整数 n。

接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 a[i,j]）。

对于任意的 x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]≥a[x,z]。

#### 输出格式
输出一个整数，表示最短 Hamilton 路径的长度。

#### 数据范围

1≤n≤20
0≤a[i,j]≤107

#### 输入样例：
```
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
```
#### 输出样例：
```
18
```
#### 闫氏Dp分析法
![](../图库/42785_4f9319bcdf-QQ浏览器截图20200816153106.png)

#### 代码
```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N], w[N][N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> w[i][j];//输入权重
        }
    }

    memset(f, 0x3f, sizeof(f));//属性min 需要初始化max
    f[1][0] = 0;//起始点
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)//遍历是f[i][j]
        {
            if(i >> j & 1)// i里有j的情况
                for(int k = 0; k < n; k++)
                {
                    if(i - (1 << j) >> k & 1)// 去掉j后 k需要仍在
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][i]);
                }
        }
    }

    cout << f[(1 << n) - 1][n-1] << endl;//输出结果
    return 0;
}
```
### 2.2 AcWing 731. 毕业旅行问题

小明目前在做一份毕业旅行的规划。

打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。

由于经费有限，希望能够通过合理的路线安排尽可能的省些路上的花销。

给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。

注意：北京为 1 号城市。

#### 输入格式
城市个数 n。

城市间的车票价钱 n 行 n 列的矩阵 m[n][n]。

#### 输出格式
输出一个整数，表示最小车费花销。

#### 数据范围
1<n≤20,包括北京
车票价格均不超过 1000 元。

#### 输入样例：
```
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
```
#### 输出样例：
 ```
 13
 ```

#### 说明
共 4 个城市，城市 1 和城市 1 的车费为 0，城市 1 和城市 2 之间的车费为 2，城市 1 和城市 3 之间的车费为 6，城市 1 和城市 4 之间的车费为 5，以此类推。

假设任意两个城市之间均有单程票可买，且价格均在 1000 元以内，无需考虑极端情况。

#### 闫氏Dp分析法
同 AcWing 91.最短Hamilton距离

#### 代码
```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N], w[N][N], n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> w[i][j]; 
        }
    }

    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i = 1; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >> j & 1)
            {
                for(int k = 0; k < n; k++)
                {
                    if(i - (1 << j) >> k & 1)
                    {
                        f[i][j] = min(f[i - (1 << j)][k] + w[k][j], f[i][j]);
                    }
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int k = 1; k < n; k++) ans = min(f[(1 << n) - 1][k] + w[k][0], ans);
    cout << ans;
    return 0;
}
```

### 2.3 [NOIP2016 提高组] 愤怒的小鸟

#### 题目描述

`Kiana` 最近沉迷于一款神奇的游戏无法自拔。

简单来说，这款游戏是在一个平面上进行的。

有一架弹弓位于 $(0,0)$ 处，每次 `Kiana` 可以用它向第一象限发射一只红色的小鸟，小鸟们的飞行轨迹均为形如 $y=ax^2+bx$ 的曲线，其中 $a,b$ 是` Kiana` 指定的参数，且必须满足 $a < 0$，$a,b$ 都是实数。

当小鸟落回地面（即 $x$ 轴）时，它就会瞬间消失。

在游戏的某个关卡里，平面的第一象限中有 $n$ 只绿色的小猪，其中第 $i$ 只小猪所在的坐标为 $\left(x_i,y_i \right)$。

如果某只小鸟的飞行轨迹经过了 $\left( x_i, y_i \right)$，那么第 $i$ 只小猪就会被消灭掉，同时小鸟将会沿着原先的轨迹继续飞行；

如果一只小鸟的飞行轨迹没有经过 $\left( x_i, y_i \right)$，那么这只小鸟飞行的全过程就不会对第 $i$ 只小猪产生任何影响。

例如，若两只小猪分别位于 $(1,3)$ 和 $(3,3)$，`Kiana` 可以选择发射一只飞行轨迹为 $y=-x^2+4x$ 的小鸟，这样两只小猪就会被这只小鸟一起消灭。

而这个游戏的目的，就是通过发射小鸟消灭所有的小猪。

这款神奇游戏的每个关卡对 `Kiana `来说都很难，所以` Kiana `还输入了一些神秘的指令，使得自己能更轻松地完成这个游戏。这些指令将在【输入格式】中详述。

假设这款游戏一共有 $T$ 个关卡，现在 `Kiana `想知道，对于每一个关卡，至少需要发射多少只小鸟才能消灭所有的小猪。由于她不会算，所以希望由你告诉她。

#### 输入格式

第一行包含一个正整数 $T$，表示游戏的关卡总数。

下面依次输入这 $T$ 个关卡的信息。每个关卡第一行包含两个非负整数 $n,m$，分别表示该关卡中的小猪数量和 Kiana 输入的神秘指令类型。接下来的 $n$ 行中，第 $i$ 行包含两个正实数 $x_i,y_i$，表示第 $i$ 只小猪坐标为 $(x_i,y_i)$。数据保证同一个关卡中不存在两只坐标完全相同的小猪。

如果 $m=0$，表示` Kiana `输入了一个没有任何作用的指令。

如果 $m=1$，则这个关卡将会满足：至多用 $\lceil n/3 + 1 \rceil$ 只小鸟即可消灭所有小猪。

如果 $m=2$，则这个关卡将会满足：一定存在一种最优解，其中有一只小鸟消灭了至少 $\lfloor n/3 \rfloor$ 只小猪。

保证 $1\leq n \leq 18$，$0\leq m \leq 2$，$0 < x_i,y_i < 10$，输入中的实数均保留到小数点后两位。

上文中，符号 $\lceil c \rceil$ 和 $\lfloor c \rfloor$ 分别表示对 $c$ 向上取整和向下取整，例如：$\lceil 2.1 \rceil = \lceil 2.9 \rceil = \lceil 3.0 \rceil = \lfloor 3.0 \rfloor = \lfloor 3.1 \rfloor = \lfloor 3.9 \rfloor = 3$。

#### 输出格式

对每个关卡依次输出一行答案。

输出的每一行包含一个正整数，表示相应的关卡中，消灭所有小猪最少需要的小鸟数量。

#### 样例 #1

#### 样例输入 #1

```
2
2 0
1.00 3.00
3.00 3.00
5 2
1.00 5.00
2.00 8.00
3.00 9.00
4.00 8.00
5.00 5.00
```

#### 样例输出 #1

```
1
1
```

#### 样例 #2

#### 样例输入 #2

```
3
2 0
1.41 2.00
1.73 3.00
3 0
1.11 1.41
2.34 1.79
2.98 1.49
5 0
2.72 2.72
2.72 3.14
3.14 2.72
3.14 3.14
5.00 5.00
```

#### 样例输出 #2

```
2
2
3
```

#### 样例 #3

#### 样例输入 #3

```
1
10 0
7.16 6.28
2.02 0.38
8.33 7.78
7.68 2.09
7.46 7.86
5.77 7.44
8.24 6.72
4.42 5.11
5.42 7.79
8.15 4.99
```

#### 样例输出 #3

```
6
```

#### 提示

【样例解释1】

这组数据中一共有两个关卡。

第一个关卡与【问题描述】中的情形相同，$2$只小猪分别位于$(1.00,3.00)$和 $(3.00,3.00)$，只需发射一只飞行轨迹为$y = -x^2 + 4x$的小鸟即可消灭它们。

第二个关卡中有$5$只小猪，但经过观察我们可以发现它们的坐标都在抛物线 $y = -x^2 + 6x$上，故`Kiana`只需要发射一只小鸟即可消灭所有小猪。

【数据范围】

| 测试点编号 |   $n\leqslant$ |   $m=$ |  $T\leqslant$ |
| :----------: | :----------: | :----------: | :----------: |
|   $1$ |   $2$ |   $0$ |  $10$ |
|   $2$ |   $2$ |   $0$ |  $30$ |
|   $3$ |   $3$ |   $0$ |  $10$ |
|   $4$ |   $3$ |   $0$ |  $30$ |
|   $5$ |   $4$ |   $0$ |  $10$ |
|   $6$ |   $4$ |   $0$ |  $30$ |
|   $7$ |   $5$ |   $0$ |  $10$ |
|   $8$ |   $6$ |   $0$ |  $10$ |
|   $9$ |   $7$ |   $0$ |  $10$ |
|   $10$ |   $8$ |   $0$ |  $10$ |
|   $11$ |   $9$ |   $0$ |  $30$ |
|   $12$ |   $10$ |   $0$ |  $30$ |
|   $13$ |   $12$ |   $1$ |  $30$ |
|   $14$ |   $12$ |   $2$ |  $30$ |
|   $15$ |   $15$ |   $0$ |  $15$ |
|   $16$ |   $15$ |   $1$ |  $15$ |
|   $17$ |   $15$ |   $2$ |  $15$ |
|   $18$ |   $18$ |   $0$ |  $5$ |
|   $19$ |   $18$ |   $1$ |  $5$ |
|   $20$ |   $18$ |   $2$ |  $5$ |

#### 闫氏Dp分析法
![](../图库/愤怒1.png)
![](../图库/愤怒2.png)

#### 代码 
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, double> PDD;

const int N = 18, M = 1 << N;
const double eps = 1e-6;

PDD q[N];
int path[N][N], f[M], T, n, m;//path记录通过i j 的抛物线所经过的所有点

bool cmp(double a, double b)
{
    if(fabs(a-b) < eps) return true;
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin>> q[i].first >> q[i].second;
        }

        memset(path, 0, sizeof(path));
        for(int i = 0; i < n; i++)
        {
            path[i][i] = 1 << i;
            for(int j = 0; j < n; j++)
            {
                double x1 = q[i].first, y1 = q[i].second, x2 = q[j].first, y2 = q[j].second;

                //计算抛物线
                if(cmp(x1, x2)) continue;
                double a = (y1/x1-y2/x2)/(x1 - x2);
                double b = (y1/x1 - a * x1);
                if(a > 0 || cmp(a, 0.0)) continue; // 需要a < 0

                //计算path[i][j] 覆盖点状态
                for(int k = 0; k < n; k++)
                {
                    double x = q[k].first, y = q[k].second;
                    if(cmp(a*x*x+ b*x, y)) path[i][j] += 1 << k;
                }  
            }
        }

        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for(int i = 0; i < 1 << n; i++)
        {
            int x = 0;
            for(int j = 0; j < n; j++)
            {
                if(i >> j & 1) continue;
                x = j;
                break;
            }

            for(int k = 0; k < n; k++)//通过没经过的点x 和 其他任意一点的抛物线
            {
                f[i | path[x][k]] = min(f[i | path[x][k]], f[i] + 1);
            }

        }

        cout << f[(1 << n) - 1] << endl;//全部通过
    }

    return 0;
}
```