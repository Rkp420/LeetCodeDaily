#include <iostream>
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-iii/submissions/1640792105/?envType=daily-question&envId=2025-05-22

class Solution
{
public:
    int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
    {
        int queryIndex = 0;
        priority_queue<int> available;                       // available `r`s
        priority_queue<int, vector<int>, greater<>> running; // running `r`s

        ranges::sort(queries);

        for (int i = 0; i < nums.size(); ++i)
        {
            while (queryIndex < queries.size() && queries[queryIndex][0] <= i)
                available.push(queries[queryIndex++][1]);
            while (!running.empty() && running.top() < i)
                running.pop();
            while (nums[i] > running.size())
            {
                if (available.empty() || available.top() < i)
                    return -1;
                running.push(available.top()), available.pop();
            }
        }

        return available.size();
    }
};
int main()
{
    return 0;
}