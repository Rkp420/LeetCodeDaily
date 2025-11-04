#include <iostream>
using namespace std;

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i + k <= n; i++){
            unordered_map<int, int> freq;

            for(int j = i; j < i + k; j++){
                freq[nums[j]]++;
            }

            vector<pair<int, int>> ele;
            for(auto &p: freq) ele.push_back({p.first, p.second});

            sort(ele.begin(), ele.end(), [](auto &a, auto &b){
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            int sum = 0; 
            int count = 0;
            for(auto &[v, f] : ele){
                if(count == x) break;
                sum += v * f;
                count++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

int main()
{
    return 0;
}