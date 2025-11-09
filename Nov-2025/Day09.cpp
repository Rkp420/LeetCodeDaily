#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-operations-to-obtain-zero/?envType=daily-question&envId=2025-11-09

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;

        while(num1 && num2){
            if(num1 >= num2){
                num1 -= num2;
            }
            else{
                num2 -= num1;
            }
            ans++;
        }

        return ans;
    }
};

int main()
{
    return 0;
}