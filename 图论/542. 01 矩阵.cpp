#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nr = mat.size();
        int nc = mat[0].size();
        vector<vector<int>> out = mat;
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                queue<pair<int, int>> box;
                box.emplace(i,j);
                int ans = 0;
                bool isdone = false;
                while (!box.empty() && !isdone)
                {
                    int m = box.size();
                    while (m--)
                    {
                        auto [x, y] = box.front();
                        box.pop();
                        if (mat[x][y] == 0)
                        {
                            //cout << "x: " << x << "y: " << y << "ans: " << ans  << "m: " << m << endl;
                            out[i][j] = ans;
                            isdone = true;
                            break;
                        }
                        //cout<< "////////////////" << endl;
                        for (int step = 0; step < 4; step++)
                        {
                            int nx = x + dx[step];
                            int ny = y + dy[step];

                            if (nx >= 0 && nx < nr && ny >= 0 && ny < nc)
                            {
                                box.emplace(nx, ny);
                            }
                              
                        }
                    }
                    ans++;
                }
                
            }
            
        }
        return out;
    }
};