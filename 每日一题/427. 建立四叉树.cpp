#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* dfs(vector<vector<int>> &grid, int rb, int cb, int re, int ce)
    {
        for (int i = rb; i < re; ++i)
        {
            for (int j = cb; j < ce; j++)
            {
                if (grid[i][j] != grid[rb][cb])
                {
                    return new Node{
                        true,
                        false,
                        dfs(grid, rb, cb, (rb + re) / 2, (cb + ce) / 2),
                        dfs(grid, rb, (cb + ce) / 2, (rb + re) / 2, ce),
                        dfs(grid, (rb + re) / 2, cb, re, (cb + ce) / 2),
                        dfs(grid, (rb + re) / 2, (cb + ce) / 2, re, ce),
                    };
                }   
            }  
        }
        return new Node(grid[rb][cb], true);
        
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size(), grid.size());
    }
};

/*
dfs(r0, c0, (r0 + r1) // 2, (c0 + c1) // 2),
                dfs(r0, (c0 + c1) // 2, (r0 + r1) // 2, c1),
                dfs((r0 + r1) // 2, c0, r1, (c0 + c1) // 2),
                dfs((r0 + r1) // 2, (c0 + c1) // 2, r1, c1),

*/

class Solution {
public:
    Node* dfs(vector<vector<int>> &grid, int x, int y, int len){
        for(int i = x; i < x +  len ; i++){
            for(int j = y; j < y +  len ; j++){
                //如果不是叶子节点，直接切割即可
                if(grid[i][j] != grid[x][y]){
                    return new Node(
                        grid[i][j],
                        false,
                        dfs(grid, x, y, len/2),
                        dfs(grid, x, y + (len+1)/2, len/2),
                        dfs(grid, x+(len+1)/2, y, len/2),
                        dfs(grid, x+(len+1)/2, y+(len + 1)/2, len/2)
                    );
                }
            }
        }
        //如果是叶子节点
        return new Node(grid[x][y], true);
        
    }
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, 0, 0, grid.size());
    }
};

/*
class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        function<Node*(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
            for (int i = r0; i < r1; ++i) {
                for (int j = c0; j < c1; ++j) {
                    if (grid[i][j] != grid[r0][c0]) { // 不是叶节点
                        return new Node(
                                true,
                                false,
                                dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
                                dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
                                dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
                                dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
                        );
                    }
                }
            }
            // 是叶节点
            return new Node(grid[r0][c0], true);
        };
        return dfs(0, 0, grid.size(), grid.size());
    }
};
*/


