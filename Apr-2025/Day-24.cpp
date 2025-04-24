#include <iostream>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();

        unordered_set<int> freq;

        for (int num : nums)
            freq.insert(num);
        int dis_el = freq.size();

        int count = 0;
        unordered_map<int, int> temp;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            temp[nums[j]]++;

            while (temp.size() == dis_el)
            {
                count += n - j;

                temp[nums[i]]--;
                if (temp[nums[i]] == 0)
                {
                    temp.erase(nums[i]);
                }
                i++;
            }
        }

        return count;
    }
};
int main()
{
    return 0;
}