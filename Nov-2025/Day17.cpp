#include <iostream>
using namespace std;

// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/submissions/1832258134/?envType=daily-question&envId=2025-11-17

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                if(prev == -1){
                    prev = i;
                }
                else{
                    int gap = (i - prev) - 1;
                    if(gap < k) return false;
                    prev = i;
                }
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}