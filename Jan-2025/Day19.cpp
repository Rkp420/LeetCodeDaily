
// LeetCode: 407 --> https://leetcode.com/problems/trapping-rain-water-ii/solutions/6293230/trapping-rain-water-ii/?envType=daily-question&envId=2025-01-19


#include <iostream>
using namespace std;

class Solution
{
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();    // No of Rows
        int n = heightMap[0].size(); // No of Cols

        // Defining Min heap to find the minHeight Boundary Cell
        priority_queue<PP, vector<PP>, greater<>> pq;

        // Making a visited array for tracking the visited Cell
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // It's Time to Push all the boundary Cells
        // First Row and last Row
        for (int i = 0; i < n; i++)
        {
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[m - 1][i], {m - 1, i}});

            visited[0][i] = true;
            visited[m - 1][i] = true;
        }

        // First Col and Last Col
        for (int i = 1; i < m - 1; i++)
        {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        // Main Work
        int water = 0;
        while (!pq.empty())
        {
            PP curr = pq.top();
            pq.pop();

            int height = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Traversing in all Four directions from this current Roof
            for (auto dir : direction)
            {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
                {
                    water += max(height - heightMap[i_][j_], 0);
                    visited[i_][j_] = true;
                    pq.push({max(height, heightMap[i_][j_]), {i_, j_}});
                }
            }
        }

        return water;
    }
};

int main()
{
    return 0;
}