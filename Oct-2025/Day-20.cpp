// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/?envType=daily-question&envId=2025-10-20

#include <iostream>
using namespace std;

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans = 0;
        for (string op : operations)
        {
            if (op == "X++" || op == "++X")
                ans++;
            else
                ans--;
        }

        return ans;
    }
};

int main()
{
    return 0;
}