#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2025-03-26

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {

        int remainder = grid[0][0] % x;

        vector<int> vec;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] % x != remainder)
                    return -1;
                vec.push_back(grid[i][j]);
            }
        }

        // Find the Meeting Poing For Optimal Operation
        sort(begin(vec), end(vec));
        int L = vec.size();

        int target = vec[L / 2];

        int noOfOperations = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            noOfOperations += (abs(target - vec[i]) / x);
        }

        return noOfOperations;
    }
};

// Slightly Improved
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {

        int remainder = grid[0][0] % x;

        vector<int> vec;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] % x != remainder)
                    return -1;
                vec.push_back(grid[i][j]);
            }
        }

        // Find the Meeting Poing For Optimal Operation
        // sort(begin(vec), end(vec));
        int L = vec.size();
        nth_element(begin(vec), begin(vec) + L / 2, end(vec));

        int target = vec[L / 2];

        int noOfOperations = 0;
        for (int &num : vec)
        {
            noOfOperations += (abs(target - num) / x);
        }

        return noOfOperations;
    }
};

int main()
{
    return 0;
}