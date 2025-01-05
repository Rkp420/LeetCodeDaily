#include <iostream>
using namespace std;

// https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.length();
        vector<int> diff(n + 1, 0);

        // Build the difference array
        for (const auto &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            int value = direction == 1 ? 1 : -1;

            diff[start] += value;
            if (end + 1 < n)
            {
                diff[end + 1] -= value;
            }
        }

        // Apply the accumulated shifts to the string
        int shift = 0;
        for (int i = 0; i < n; i++)
        {
            shift += diff[i];
            int offset = (s[i] - 'a' + shift) % 26;
            if (offset < 0)
                offset += 26; // Handle negative wrapping
            s[i] = 'a' + offset;
        }

        return s;
    }
};

int main()
{
    return 0;
}