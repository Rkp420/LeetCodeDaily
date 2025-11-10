#include <iostream>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/submissions/1825738304/?envType=daily-question&envId=2025-11-10

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        stack<int> st;

        for (int num : nums)
        {
            while (!st.empty() && st.top() > num)
            {
                ans++;
                st.pop();
            }

            if (num != 0 && (st.empty() || st.top() < num))
            {
                st.push(num);
            }
        }

        return ans + st.size();
    }
};

int main()
{
    return 0;
}