#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        // Step 1: Count the frequency of each element
        for (int &num : nums)
            freq[num]++;

        int dominantEle = -1;
        int dominantEleFreq = 0;
        int n = nums.size(); // Store nums.size() for easy access

        // Step 2: Find the dominant element (whose frequency is more than n/2)
        for (auto &it : freq)
        {
            if (it.second * 2 > n)
            {
                dominantEle = it.first;
                dominantEleFreq = it.second;
                break;
            }
        }

        // If no dominant element is found
        if (dominantEle == -1)
            return -1;

        int count = 0;

        // Step 3: Find the minimum index where both conditions are satisfied
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == dominantEle)
                count++;

            // Check if left and right halves satisfy the dominant condition
            if (count * 2 > (i + 1) && (dominantEleFreq - count) * 2 > (n - (i + 1)))
            {
                return i; // Return the minimum index
            }
        }

        return -1; // No valid split found
    }
};

int main()
{
    return 0;
}