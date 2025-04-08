#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int operations = 0;

        while (i < n)
        {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int j = i; j < n; j++)
            {
                if (seen.count(nums[j]))
                {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(nums[j]);
            }

            if (!hasDuplicate)
                break;

            // Simulate removing first 3 elements by moving i forward
            i += 3;
            operations++;
        }

        return operations;
    }
};

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int operations = 0;

        while (true)
        {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            // Check for duplicates
            for (int num : nums)
            {
                if (seen.count(num))
                {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }

            // If all elements are unique, break
            if (!hasDuplicate)
                break;

            // Perform an operation: remove first 3 elements
            operations++;
            int toRemove = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + toRemove);
        }

        return operations;
    }
};
int main()
{
    return 0;
}