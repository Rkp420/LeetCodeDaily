// https: // leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/?envType=daily-question&envId=2025-10-22

#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());
        map<int, int> range;
        map<int, int> fre;
        for (int i = 0; i < nums.size(); i++)
        {
            fre[nums[i]]++;
            int left = nums[i] - k;
            int right = nums[i] + k;
            range[left]++;
            range[right + 1]--;
            range[nums[i]] += 0;
        }

        int ans = 1;

        int previousRangeSum = 0;

        for (auto it = range.begin(); it != range.end(); it++)
        {

            it->second += previousRangeSum;
            previousRangeSum = it->second;
            int currentElementFrequency = fre[it->first];
            int maxFrequency = it->second - currentElementFrequency;
            maxFrequency = min(maxFrequency, numOperations);
            maxFrequency += currentElementFrequency;
            ans = max(ans, maxFrequency);
        }

        return ans;
    }
};

int main()
{
    return 0;
}