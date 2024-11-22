// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

#include <iostream>
using namespace std;
class Solution
{
public:
    string makeFancyString(string s)
    {
        string result = ""; // To store the final "fancy" string
        int count = 1;      // To track consecutive identical characters

        result += s[0]; // Add the first character to the result

        // Start traversing from the second character
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count++; // Increment count if current char is the same as previous
            }
            else
            {
                count = 1; // Reset count if it's a new character
            }

            // Only add the character if count is less than 3
            if (count < 3)
            {
                result += s[i];
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}