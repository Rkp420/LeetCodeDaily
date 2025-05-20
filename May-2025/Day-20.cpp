#include <iostream>
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (vector<int> q : queries)
        {
            prefix[q[0]]++;
            if (q[1] + 1 < n)
                prefix[q[1] + 1]--;
        }

        for (int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if ((nums[i] - prefix[i]) > 0)
                return false;
        }

        return true;
    }
};

int main()
{
    return 0;
}