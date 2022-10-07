//https://www.luogu.com.cn/problem/solution/P7074
#include <iostream>

using namespace std;

/*
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1200][1200];//地图
int vis[1200][1200];//记录每一步走到所加之和
int maxn=INT_MIN;//记录是否访问过
int dir[3][2]={{0,1},{1,0},{-1,0}};//上，下，右
void dfs(int x,int y){
    if(x<1||y<1||x>n||y>m){//判断越界
        return;
    }
    else if(x==n&&y==m){//如果走到终点
        if(maxn<vis[x][y]){//判断是否比maxn大
            maxn=vis[x][y];//更新maxn值
        }
    }
    else{//搜索主程序
        for(int i=0;i<3;i++){
            if(vis1[x+dir[i][0]][y+dir[i][1]]==0){//如果没有访问过
                vis1[x+dir[i][0]][y+dir[i][1]]=1;
                vis[x+dir[i][0]][y+dir[i][1]]=vis[x][y]+a[x+dir[i][0]][y+dir[i][1]];
                dfs(x+dir[i][0],y+dir[i][1]);//搜索
                vis1[x+dir[i][0]][y+dir[i][1]]=0;
                vis[x+dir[i][0]][y+dir[i][1]]=vis[x][y];//回溯一步
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    vis[1][1]=a[1][1];//首位需要事先标记
    dfs(1,1);
    cout<<maxn;
    return 0;//别忘啦
}
*/

#include <iostream>
using namespace std;
int n,m;
int a[1200][1200];//地图
int vis[1200][1200];//记录每一步走到所加之和
int vis1[1200][1200];
int maxn=INT_MIN;//记录是否访问过
int dir[3][2]={{0,1},{1,0},{-1,0}};//上，下，右
void dfs(int x,int y){
    if(x<1||y<1||x>n||y>m){//判断越界
        return;
    }
    else if(x==n&&y==m){//如果走到终点
        if(maxn<vis[x][y]){//判断是否比maxn大
            maxn=vis[x][y];//更新maxn值
        }
    }
    else{//搜索主程序
        for(int i=0;i<3;i++){
            if(vis1[x+dir[i][0]][y+dir[i][1]]==0){//如果没有访问过
                vis1[x+dir[i][0]][y+dir[i][1]]=1;
                vis[x+dir[i][0]][y+dir[i][1]]=vis[x][y]+a[x+dir[i][0]][y+dir[i][1]];
                dfs(x+dir[i][0],y+dir[i][1]);//搜索
                vis1[x+dir[i][0]][y+dir[i][1]]=0;
                vis[x+dir[i][0]][y+dir[i][1]]=vis[x][y];//回溯一步
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    vis[1][1]=a[1][1];//首位需要事先标记
    dfs(1,1);
    cout<<maxn;
    return 0;//别忘啦
}

//01是表示当前的方向，因为不能回头，所以只有两种
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int f[1005][1005][2],a[1005][1005],n,m;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[j][i];
	swap(n,m);
	for(int i=0;i<=n+1;i++)
	for(int j=0;j<=m+1;j++)
	f[i][j][0]=f[i][j][1]=(int)(-1e18);
	f[1][1][0]=f[1][1][1]=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i!=1)
			{
				f[i][j][0]=max(f[i][j][0],max(f[i-1][j][0],f[i-1][j][1])+a[i][j]);
				f[i][j][1]=max(f[i][j][1],max(f[i-1][j][0],f[i-1][j][1])+a[i][j]);
			}
			if(j!=1)
			{
				f[i][j][0]=max(f[i][j][0],f[i][j-1][0]+a[i][j]);
			}
		}
		for(int j=m;j>=1;j--)
		{
			if(j!=m)
			f[i][j][1]=max(f[i][j][1],f[i][j+1][1]+a[i][j]);
		}
	}
	cout<<max(f[n][m][0],f[n][m][1]);
	return 0;
}