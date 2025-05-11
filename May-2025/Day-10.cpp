#include <iostream>  // For std::cout (if needed in main) and general I/O
#include <vector>    // For std::vector
#include <string>    // For std::string
#include <numeric>   // For std::accumulate
#include <limits>    // (Though you're not using anything from <limits> currently — optional)
#include <algorithm> // For std::ranges::sort (C++20) and std::greater
using namespace std;

// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        const long sum1 = accumulate(nums1.begin(), nums1.end(), 0L);
        const long sum2 = accumulate(nums2.begin(), nums2.end(), 0L);
        const int zero1 = ranges::count(nums1, 0);
        const int zero2 = ranges::count(nums2, 0);
        if (zero1 == 0 && sum1 < sum2 + zero2)
            return -1;
        if (zero2 == 0 && sum2 < sum1 + zero1)
            return -1;
        return max(sum1 + zero1, sum2 + zero2);
    }
};

int main()
{
    return 0;
}