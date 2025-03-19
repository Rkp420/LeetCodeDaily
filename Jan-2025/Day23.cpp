
// LeetCode 1267 : https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23

#include <iostream>
using namespace std;

// BruteForce Approach
class Solution1
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        // Time to Traverse
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Go Through Whole Row and Find How many Servers it Can
                    // Connect
                    bool flag = false;
                    for (int col = 0; col < n; col++)
                    {
                        if (grid[i][col] == 1 && j != col)
                        {
                            ans++;
                            flag = true;
                            break;
                        }
                    }
                    // Go Through Whole col and Find How many Servers it Can
                    // Connect
                    if (!flag)
                    {
                        for (int row = 0; row < m; row++)
                        {
                            if (grid[row][j] == 1 && row != i)
                            {
                                ans++;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// Optimised Approach
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);

        // Second Step : Store Information of Servers
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    indexColCount[j]++;
                    indexRowCount[i]++;
                }
            }
        }

        // Final Step
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && (indexRowCount[i] > 1 || indexColCount[j] > 1))
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}