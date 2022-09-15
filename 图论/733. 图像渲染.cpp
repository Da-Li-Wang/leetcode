#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//广度优先搜索
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int curcolor = image[sr][sc];
        
        if (curcolor == newColor)
        {
            return image;
        }

        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < m && my >= 0 && my < n && image[mx][my] == curcolor)
                {
                    que.emplace(mx, my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
};


//深度优先搜索
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newcolor)
    {
        if (image[x][y] == color)
        {
            image[x][y] = newcolor;
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size())
                {
                    dfs(image, mx, my, color, newcolor);
                }
                
            }
            
        }
        
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int curcolor = image[sr][sc];
        if (curcolor != newColor)
        {
            dfs(image, sr, sc, curcolor, newColor);
        }
        return image;
    }
};