#include <iostream>
using namespace std;

// https : // leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19

// Brute - force : Backtracking
class Solution1
{
public:
    int backtrack(vector<int> &nums, int index, int ops)
    {
        // Base case: If all elements are 1, return the number of operations
        if (all_of(nums.begin(), nums.end(), [](int x)
                   { return x == 1; }))
        {
            return ops;
        }

        if (index >= nums.size() - 2)
            return INT_MAX; // No more valid flips

        // Try flipping elements at index, index+1, index+2
        nums[index] ^= 1;
        nums[index + 1] ^= 1;
        nums[index + 2] ^= 1;

        int flip = backtrack(nums, index + 1, ops + 1); // Recur with flipped array

        // Undo the flip (backtrack)
        nums[index] ^= 1;
        nums[index + 1] ^= 1;
        nums[index + 2] ^= 1;

        // Try without flipping and move to the next index
        int noFlip = backtrack(nums, index + 1, ops);

        return min(flip, noFlip);
    }

    int minOperations(vector<int> &nums)
    {
        int res = backtrack(nums, 0, 0);
        return (res == INT_MAX) ? -1 : res;
    }
};

// Optimal : Greedy
class Solution2
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int operations = 0;

        for (int i = 0; i <= n - 3; i++)
        {
            if (nums[i] == 0)
            { // Flip window if a '0' is found
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }

        // Check if the last two elements are still '0', which means impossible
        for (int i = n - 2; i < n; i++)
        {
            if (nums[i] == 0)
                return -1;
        }

        return operations;
    }
};

int main()
{
    return 0;
}