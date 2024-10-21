#include <iostream>
using namespace std;
class Solution
{
public:
    int maximumSwap(int num)
    {
        // If the number is a single digit or less than 11, swapping doesn't change it.
        if (num <= 11)
            return num;

        // Convert the number to a string for easy manipulation.
        string nums = to_string(num);
        int n = nums.size();

        // Find the pivot index where a smaller number appears before a larger number.
        int pi = -1; // -1 indicates no pivot found yet.
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                pi = i;
                break;
            }
        }

        // If no pivot is found, the number is already the largest possible permutation.
        if (pi == -1)
            return num;

        // Find the largest digit after the pivot index.
        int swapI = pi + 1;
        for (int j = pi + 1; j < n; j++)
        {
            if (nums[j] >= nums[swapI])
            {
                swapI = j;
            }
        }

        // Find the leftmost digit equal to or smaller than nums[swapI] before the pivot.
        int leftmost = pi;
        for (int i = 0; i <= pi; i++)
        {
            if (nums[i] < nums[swapI])
            {
                leftmost = i;
                break;
            }
        }

        // Swap the digit at leftmost with the largest digit after the pivot.
        swap(nums[leftmost], nums[swapI]);

        // Convert the modified string back to an integer.
        return stoi(nums);
    }
};
int main()
{
    return 0;
}