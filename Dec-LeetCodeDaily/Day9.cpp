#include <iostream>
using namespace std;

// Brute Force 
class Solution
{
public:
    bool isSpecial(vector<int> &querie, vector<int> &nums)
    {
        int i = querie[0];
        int j = querie[1];

        for (int k = i; k < j; k++)
        {
            // Check if both are even or both are odd
            if ((nums[k] % 2 == 0 && nums[k + 1] % 2 == 0) ||
                (nums[k] % 2 != 0 && nums[k + 1] % 2 != 0))
            {
                return false;
            }
        }

        return true;
    }

    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        
        vector<bool> ans(m, false);

        for (int i = 0; i < m; i++)
        {
            if (isSpecial(queries[i], nums))
                ans[i] = true;
        }

        return ans;
    }
};

// Using Binary Search
class Solution1
{
public:

    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> prefix(n , 0);

        // Step 1 : Make 1 Where Non Parity happens
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == nums[i - 1] % 2) prefix[i] = 1; 
        }

        // Step 2 : Start Binary Search For Given Operation
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
        }
    }
};


int main()
{
    return 0;
}
