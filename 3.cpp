#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
unordered_map<char,char> mp;
vector<vector<int>> nexts = {{1,0},{-1,0},{0,1},{0,-1}};
int res;
void bfs(vector<string>& grid, int i, int j, vector<vector<int>>& visited,int step){
    if (i == grid.size()-1 && j == grid[0].size()-1)
    {
        res = min(res,step);
        return ;
    }
    visited[i][j] = 1;
    for(int k = 0;k < 4; ++k){
        int nexti = nexts[k][0] + i,nextj = nexts[k][1] + j;
        if(nexti >= 0 && nexti < grid.size() && nextj >= 0 && nextj < grid[0].size() && visited[nexti][nextj] == 0){
            if(mp[grid[i][j]] != grid[nexti][nextj]){
                bfs(grid,nexti,nextj,visited,step+1);
            }
        }
    }
    visited[i][j] = 0;
    
}
int main(){
    int n = 3,m = 3;
    vector<string> grid={"red","der","edr"};
    mp['r'] = 'd';
    mp['d'] = 'e';
    mp['e'] = 'r';
    vector<vector<int>> visited(n,vector<int>(m));
    res = INT16_MAX;
    bfs(grid,0,0,visited,0);
    if(res == INT16_MAX)cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}