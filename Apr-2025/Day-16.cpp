#include <iostream>
using namespace std;

// Using Sliding Window Hashtable
class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        int n = nums.size();

        long long pairs = 0, res = 0;
        unordered_map<int, int> freq;

        int i = 0;
        for(int j = 0; j < n; j++){
            pairs += freq[nums[i]];
            freq[nums[i]]++;

            while(pairs >= k){
                res += (n - j);
                freq[nums[i]]--;
                pairs -= freq[nums[i]];
                i++;
            }
        }

        return res;
    }
};
int main()
{
    return 0;
}