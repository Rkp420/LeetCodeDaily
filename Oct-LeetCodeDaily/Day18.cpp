#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countMaxSubsets(int i, int &maxOr, vector<int> &nums, int currOr, vector<vector<int>> &t)
    {
        if (i >= nums.size())
            return maxOr == currOr;

        // Check if already we calculate their value
        if (t[i][currOr] != -1)
            return t[i][currOr];

        // Taking i
        int takingCount = countMaxSubsets(i + 1, maxOr, nums, currOr | nums[i], t);
        // Not Takint i
        int notTakingCount = countMaxSubsets(i + 1, maxOr, nums, currOr, t);

        return t[i][currOr] = takingCount + notTakingCount;
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOr = 0;
        for (int &num : nums)
            maxOr |= num;
        int currOr = 0;

        // Memoise the Problem for bigger size of nums array
        // For this problem memoisation is not a good option
        // But we will do this
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(maxOr + 1, -1));

        return countMaxSubsets(0, maxOr, nums, currOr, t);
    }
};
int main()
{
    return 0;
}