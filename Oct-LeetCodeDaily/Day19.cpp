#include <iostream>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1 || k == 1)
            return '0';

        int len = pow(2, n);

        // Case 1 : if we are on the left side
        if (k < len / 2)
        {
            return findKthBit(n - 1, k);
        }
        else if (k == len / 2)
        {
            // Case 2 : If we are on the middle
            return '1';
        }
        else
        {
            // Case 3 : if we are on the right side
            char invert_bit = findKthBit(n - 1, len - k);

            return invert_bit == '0' ? '1' : '0';
        }
    }
};

int main()
{
    return 0;
}