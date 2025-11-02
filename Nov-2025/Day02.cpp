// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/submissions/1818301135/?envType=daily-question&envId=2025-11-02

#include <iostream>
using namespace std;

class Solution
{
public:
    void updateGrid(int row, int col, vector<vector<int>> &grid)
    {
        // Up
        for (int i = row - 1; i >= 0; i--)
        {
            if (grid[i][col] == 3 || grid[i][col] == 2)
                break;
            else
                grid[i][col] = 1;
        }

        // Down
        for (int i = row + 1; i < grid.size(); i++)
        {
            if (grid[i][col] == 3 || grid[i][col] == 2)
                break;
            else
                grid[i][col] = 1;
        }

        // Left
        for (int j = col - 1; j >= 0; j--)
        {
            if (grid[row][j] == 3 || grid[row][j] == 2)
                break;
            else
                grid[row][j] = 1;
        }

        // Right
        for (int j = col + 1; j < grid[row].size(); j++)
        {
            if (grid[row][j] == 3 || grid[row][j] == 2)
                break;
            else
                grid[row][j] = 1;
        }

        return;
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // step 1 : Update guards location
        for (vector<int> v : guards)
        {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 2;
        }

        // Step 2 : Update Walls location
        for (vector<int> v : walls)
        {
            int i = v[0];
            int j = v[1];
            grid[i][j] = 3;
        }

        // Step 3 : Update the grid which colums will be guarded
        for (vector<int> v : guards)
        {
            int i = v[0];
            int j = v[1];

            // Function call to Update the grid
            updateGrid(i, j, grid);
        }

        // Step 4 : Count the no of unGuarded cells
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    count++;
            }
        }

        // Finally
        return count;
    }
};

int main()
{
    return 0;
}