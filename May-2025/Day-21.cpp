#include <iostream>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/submissions/1639818705/?envType=daily-question&envId=2025-05-21

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // For Storing Which Row Or Col to Be Zero
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n, 1);
        vector<int> col(m, 1);

        // Brute Force Approach
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        // Finally it's time to Update
        for (int i = 0; i < n; i++)
        {
            if (row[i] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (col[j] == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};

int main()
{
    return 0;
}