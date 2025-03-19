#include <iostream>
using namespace std;
// https : // leetcode.com/problems/longest-nice-subarray/submissions/1578960155/?envType=daily-question&envId=2025-03-18

// BruteForce Approach

class Solution1
{
public:
    // Normal Approach : O(N * N)
    bool isNiceSubarray1(int i, int j, vector<int> &nums)
    {
        for (int x = i; x < j; x++)
        { // Use x instead of i
            for (int y = x + 1; y <= j; y++)
            { // Check all pairs in range [i, j]
                if ((nums[x] & nums[y]) != 0)
                    return false;
            }
        }
        return true;
    }

    // Optimised Approach : O(N)
    bool isNiceSubarray2(int i, int j, vector<int> &nums)
    {
        int mask = 0;
        for (int x = i; x <= j; x++)
        {
            if (nums[x] & mask != 0)
                return false;
            else
                mask |= nums[x];
        }

        return true;
    }

    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isNiceSubarray2(i, j, nums))
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

// Better Approach
class Solution2
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int mask = 0;
            for (int j = i; j < n; j++)
            {
                if ((mask & nums[j]) != 0)
                    break;
                else
                {
                    mask |= nums[j];
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// Most Optimal : Sliding Window for Generating Subarray
class Solution3
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int left = 0, right = 0, usedBits = 0, maxLen = 0;

        while (right < nums.size())
        {
            while ((usedBits & nums[right]) != 0)
            {                           // Conflict detected
                usedBits ^= nums[left]; // Remove nums[left] from window
                left++;                 // Shrink window
            }

            usedBits |= nums[right]; // Add nums[right] to the window
            maxLen = max(maxLen, right - left + 1);
            right++; // Expand window
        }

        return maxLen;
    }
};

int main()
{
    return 0;
}