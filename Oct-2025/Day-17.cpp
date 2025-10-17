#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<long long, int> memo;
    string input;
    int maxDistinct;

    // Recursive function to find the maximum number of partitions
    int getMaxPartitions(int index, long long charMask, bool canModify)
    {
        // Create a unique key for memoization
        long long stateKey = (index << 27) | (charMask << 1) | canModify;
        if (memo.find(stateKey) != memo.end())
            return memo[stateKey];

        // Base case: reached end of string
        if (index >= input.size())
            return 0;

        int currentCharIndex = input[index] - 'a';
        long long updatedMask = charMask | (1LL << currentCharIndex);
        int uniqueCharCount = __builtin_popcountll(updatedMask);

        int bestPartitions = 0;

        // Case 1: Continue current substring
        if (uniqueCharCount > maxDistinct)
        {
            // Too many distinct chars — start new substring
            bestPartitions = 1 + getMaxPartitions(index + 1, 1LL << currentCharIndex, canModify);
        }
        else
        {
            // Continue without partition
            bestPartitions = getMaxPartitions(index + 1, updatedMask, canModify);
        }

        // Case 2: Try changing the current character (if allowed)
        if (canModify)
        {
            for (int newChar = 0; newChar < 26; ++newChar)
            {
                long long modifiedMask = charMask | (1LL << newChar);
                int modifiedCount = __builtin_popcountll(modifiedMask);

                int partitionsAfterChange;
                if (modifiedCount > maxDistinct)
                {
                    partitionsAfterChange = 1 + getMaxPartitions(index + 1, 1LL << newChar, false);
                }
                else
                {
                    partitionsAfterChange = getMaxPartitions(index + 1, modifiedMask, false);
                }

                bestPartitions = max(bestPartitions, partitionsAfterChange);
            }
        }

        return memo[stateKey] = bestPartitions;
    }

    int maxPartitionsAfterOperations(string str, int k)
    {
        input = str;
        maxDistinct = k;
        memo.clear();

        // +1 because the number of partitions = cuts + 1
        return getMaxPartitions(0, 0, true) + 1;
    }
};

int main()
{
    return 0;
}