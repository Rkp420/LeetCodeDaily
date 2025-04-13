#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13

class Solution{
    public:
        #define mod 1000000007
        long long power(long long base, long long p){
            long long result = 1;
            base = base % mod;

            while(p > 1){
                if(p % 2) result = (result * base) % mod;
                p /= 2;
                base = (base * base) % mod;
            }

            return result;
        }

        int countGoodNumbers(long long n)
        {
            long long evenPos = (n + 1) / 2; // even indices: 0, 2, 4, ...
            long long oddPos = n / 2;        // odd indices: 1, 3, 5, ...

            long long pow5 = power(5, evenPos);
            long long pow4 = power(4, oddPos);

            return (pow5 * pow4) % mod;
        }
};
int main()
{
    return 0;
}