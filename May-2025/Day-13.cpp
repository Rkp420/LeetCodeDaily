#include <iostream>
#include <numeric>
using namespace std;

// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        constexpr int kMod = 1'000'000'007;
        vector<int> count(26);

        for (const char c : s)
            ++count[c - 'a'];

        while (t-- > 0)
        {
            vector<int> newCount(26);
            // 'a' -> 'b', 'b' -> 'c', ..., 'y' -> 'z'
            for (int i = 0; i < 25; ++i)
                newCount[i + 1] = count[i];
            // 'z' -> 'ab'
            newCount[0] = count[25];
            newCount[1] = (newCount[1] + count[25]) % kMod;
            count = std::move(newCount);
        }

        return accumulate(count.begin(), count.end(), 0L) % kMod;
    }
};
int main()
{
    return 0;
}