
#include <iostream>
using namespace std;

// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/submissions/1807274397/?envType=daily-question&envId=2025-10-21

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        unordered_map<int, int> range;
        unordered_map<int, int> freq;

        int minRange = 1e9;
        int maxRange = -1e9;
        for (int num : nums)
        {
            freq[num]++;
            int left = num - k;
            int right = num + k;
            minRange = min(minRange, left);
            maxRange = max(maxRange, right);
            range[left]++;
            range[right + 1]--;
        }

        int ans = 1;
        for (int i = minRange; i <= maxRange; i++)
        {
            range[i] = range[i] + range[i - 1];
            int currEleFrequency = freq[i];
            int maxFreq = range[i] - currEleFrequency;
            maxFreq = min(maxFreq, numOperations);
            maxFreq = maxFreq + currEleFrequency;
            ans = max(ans, maxFreq);
        }

        return ans;
    }
};

int main()
{
    return 0;
}