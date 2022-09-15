#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> Dpsum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        Dpsum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                Dpsum[i][j] = Dpsum[i-1][j] + Dpsum[i][j-1] - Dpsum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*
        cout << Dpsum[row2 + 1][col2 + 1] << endl;
        cout << Dpsum[row1][col1 + 1] << endl;
        cout << Dpsum[row1 + 1][col1] << endl;
        cout << Dpsum[row1][col1] << endl;
        */
        return Dpsum[row2 + 1][col2 + 1] - Dpsum[row2 + 1][col1] - Dpsum[row1][col2 + 1] + Dpsum[row1][col1];
    }
};


