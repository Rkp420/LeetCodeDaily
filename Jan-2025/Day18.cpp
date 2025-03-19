// LeetCode: 1368 --> https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

#include <iostream>
using namespace std;

// 1st Approach : Using Backtracking
class Solution1
{
public:
    int m, n;
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int backtrack(int i, int j, vector<vector<int>> &grid, int cost, vector<vector<bool>> &visited)
    {
        if (i == m - 1 && j == n - 1)
            return cost;

        // Mark as visited
        visited[i][j] = true;
        int minCost = INT_MAX;

        for (int idx = 0; idx < 4; idx++)
        {
            int i_ = i + direction[idx][0];
            int j_ = j + direction[idx][1];

            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
            {
                int nextCost = (grid[i][j] == idx + 1) ? 0 : 1; // Add cost for direction change
                minCost = min(minCost, backtrack(i_, j_, grid, cost + nextCost, visited));
            }
        }

        // Unmark visited for backtracking
        visited[i][j] = false;

        return minCost;
    }

    int minCost(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return backtrack(0, 0, grid, 0, visited);
    }
};

// 2nd Approach: 


int main()
{
    return 0;
}