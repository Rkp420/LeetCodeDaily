#include <iostream>
#include <map>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/?envType=daily-question&envId=2025-04-09
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        // Step 1: Check if any number is less than k. If yes, return -1.
        for (int num : nums)
        {
            if (num < k)
                return -1;
        }

        // Step 2: Count frequency of each number using map
        map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        int operations = 0;

        // Step 3: Continue until all values are reduced to k
        while (true)
        {
            // Get all unique values currently in the array
            vector<int> values;
            for (auto &[key, _] : freq)
            {
                values.push_back(key);
            }

            // If the only value left is k, we are done
            if (values.size() == 1 && values[0] == k)
                break;

            // Get maximum value
            int maxVal =
                values.back(); // since map is sorted in ascending order
            if (maxVal == k)
            {
                // Already at k, no need to reduce further
                break;
            }

            // Find next lower valid value to reduce to
            int h = k;
            for (int i = values.size() - 2; i >= 0; --i)
            {
                if (values[i] < maxVal)
                {
                    h = values[i];
                    break;
                }
            }

            // Check if all values greater than h are the same (i.e.,
            // maxVal)
            for (int i = values.size() - 1; i >= 0; --i)
            {
                if (values[i] > h && values[i] != maxVal)
                {
                    return -1; // Not valid h
                }
            }

            // Perform operation: set all values > h to h
            freq[h] += freq[maxVal];
            freq.erase(maxVal);
            operations++;
        }

        // Final check: did we reach k?
        if (freq.size() == 1 && freq.count(k))
        {
            return operations;
        }
        return -1;
    }
};

int main()
{
    return 0;
}