#include <iostream>
using namespace std;

// https://leetcode.com/problems/apply-operations-to-maximize-score/description/?envType=daily-question&envId=2025-03-29

#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>

class Solution
{
public:
    int maximumScore(std::vector<int> &nums, int k)
    {
        const int n = nums.size();
        const int mx = *std::max_element(nums.begin(), nums.end());
        const std::vector<int> minPrimeFactors = sieveEratosthenes(mx + 1);
        const std::vector<int> primeScores = getPrimeScores(nums, minPrimeFactors);
        int ans = 1;
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);
        std::stack<int> stack;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!stack.empty() && primeScores[stack.top()] <= primeScores[i])
            {
                left[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }

        stack = std::stack<int>();

        for (int i = 0; i < n; ++i)
        {
            while (!stack.empty() && primeScores[stack.top()] < primeScores[i])
            {
                right[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }

        std::vector<std::pair<int, int>> numAndIndexes;
        for (int i = 0; i < n; ++i)
            numAndIndexes.emplace_back(nums[i], i);

        std::sort(numAndIndexes.begin(), numAndIndexes.end(), [&](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  { return a.first == b.first ? a.second < b.second : a.first > b.first; });

        for (const auto &[num, i] : numAndIndexes)
        {
            const long rangeCount = static_cast<long>(i - left[i]) * (right[i] - i);
            const long actualCount = std::min(rangeCount, static_cast<long>(k));
            k -= actualCount;
            ans = static_cast<long>(ans) * modPow(num, actualCount) % kMod;
        }

        return ans;
    }

private:
    static constexpr int kMod = 1'000'000'007;

    long modPow(long x, long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * modPow(x % kMod, (n - 1)) % kMod;
        return modPow(x * x % kMod, (n / 2)) % kMod;
    }

    std::vector<int> sieveEratosthenes(int n)
    {
        std::vector<int> minPrimeFactors(n + 1);
        std::iota(minPrimeFactors.begin() + 2, minPrimeFactors.end(), 2);
        for (int i = 2; i * i < n; ++i)
            if (minPrimeFactors[i] == i)
                for (int j = i * i; j < n; j += i)
                    minPrimeFactors[j] = std::min(minPrimeFactors[j], i);
        return minPrimeFactors;
    }

    std::vector<int> getPrimeScores(const std::vector<int> &nums, const std::vector<int> &minPrimeFactors)
    {
        std::vector<int> primeScores;
        for (const int num : nums)
            primeScores.push_back(getPrimeScore(num, minPrimeFactors));
        return primeScores;
    }

    int getPrimeScore(int num, const std::vector<int> &minPrimeFactors)
    {
        std::unordered_set<int> primeFactors;
        while (num > 1)
        {
            const int divisor = minPrimeFactors[num];
            primeFactors.insert(divisor);
            while (num % divisor == 0)
                num /= divisor;
        }
        return primeFactors.size();
    }
};

int main()
{
    return 0;
}