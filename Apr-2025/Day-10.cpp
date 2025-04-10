#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-powerful-integers/description/?envType=daily-question&envId=2025-04-10

class Solution
{
#define ll long long
#define MAX_DIGITS 17
    ll dp[MAX_DIGITS][2];

    // Helper: Check if number should be subtracted based on suffix and digit constraints
    static bool checkSubtract(const string &num_str, ll num_digits, const string &suffix, int limit)
    {
        if (num_digits < suffix.size())
            return false;

        string suffix_of_num = num_str.substr(num_digits - suffix.size());
        bool subtract = stoll(suffix_of_num) < stoll(suffix);

        if (subtract)
        {
            for (int i = 0; i < num_digits - suffix.size(); ++i)
            {
                if ((num_str[i] - '0') > limit)
                {
                    subtract = false;
                    break;
                }
            }
        }
        return subtract;
    }

    // Core recursive + memoized function to count valid numbers <= number_str
    ll countValidNumbers(const string &number_str, ll idx, ll max_digits,
                         bool is_tight, int limit, const string &suffix)
    {
        if (idx == max_digits)
            return 1;
        if (dp[idx][is_tight] != -1)
            return dp[idx][is_tight];

        ll low = 0, high;
        ll suffix_len = suffix.size();

        if (idx >= max_digits - suffix_len)
        {
            ll suffix_idx = idx - (max_digits - suffix_len);
            low = high = suffix[suffix_idx] - '0';
        }
        else
        {
            high = is_tight ? min<ll>(limit, number_str[idx] - '0') : limit;
        }

        ll total = 0;
        for (ll digit = low; digit <= high; ++digit)
        {
            bool new_tight = is_tight && (digit == number_str[idx] - '0');
            total += countValidNumbers(number_str, idx + 1, max_digits, new_tight, limit, suffix);
        }

        return dp[idx][is_tight] = total;
    }

    // Helper to compute number of valid values up to `num_str`
    ll solveUpTo(const string &num_str, ll num_digits, int limit, const string &suffix)
    {
        memset(dp, -1, sizeof(dp));
        ll result = countValidNumbers(num_str, 0, num_digits, true, limit, suffix);
        if (checkSubtract(num_str, num_digits, suffix, limit))
            result--;
        return result;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix)
    {
        ll suffix_val = stoll(suffix);
        string finish_str = to_string(finish);
        string start_str = to_string(start - 1);

        ll finish_digits = finish_str.size();
        ll start_digits = start_str.size();

        ll upto_finish = (finish >= suffix_val) ? solveUpTo(finish_str, finish_digits, limit, suffix) : 0;
        ll upto_start = (suffix_val < start) ? solveUpTo(start_str, start_digits, limit, suffix) : 0;

        return upto_finish - upto_start;
    }
};

class Solution
{
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s)
    {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low; // align digits
        int pre_len = n - s.size();              // prefix length

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> dfs =
            [&](int i, bool limit_low, bool limit_high) -> long long
        {
            // recursive boundary
            if (i == low.size())
            {
                return 1;
            }

            if (!limit_low && !limit_high && memo[i] != -1)
            {
                return memo[i];
            }

            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            long long res = 0;
            if (i < pre_len)
            {
                for (int digit = lo; digit <= min(hi, limit); digit++)
                {
                    res += dfs(i + 1, limit_low && digit == lo,
                               limit_high && digit == hi);
                }
            }
            else
            {
                int x = s[i - pre_len] - '0';
                if (lo <= x && x <= min(hi, limit))
                {
                    res =
                        dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                }
            }

            if (!limit_low && !limit_high)
            {
                memo[i] = res;
            }
            return res;
        };
        return dfs(0, true, true);
    }
};

class Solution
{
public:
    long long solve(string &str, string &inputSuffix, int limit)
    {
        if (str.length() < inputSuffix.length())
        {
            return 0;
        }

        long long count = 0;
        string trailString = str.substr(str.length() - inputSuffix.length()); //"00"
        //"3000" - 4
        //"12" - 2
        int remainL = str.length() - inputSuffix.length();

        for (int i = 0; i < remainL; i++)
        {
            int digit = str[i] - '0';

            if (digit <= limit)
            {
                count += digit * pow(limit + 1, remainL - i - 1);
            }
            else
            {
                count += pow(limit + 1, remainL - i); // 5^pos
                return count;
            }
        }

        if (trailString >= inputSuffix)
        {
            count += 1;
        }

        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);

        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};

int main()
{
    return 0;
}