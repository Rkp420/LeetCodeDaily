#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        if (n == 0)
            return -1;

        vector<int> freq(3, 0);

        // Step 1 : Storing the frequency of the characters
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        // Step 2 : Check if any char is appear less
        if (freq[0] < k || freq[1] < k || freq[2] < k)
            return -1;

        // Step 3 : Set Max freq allowed in the Window
        int required[3] = {freq[0] - k, freq[1] - k, freq[2] - k};

        // Step 4 : Creating and Handling our Window
        int left = 0;
        int maxLength = 0;
        vector<int> current(3, 0);

        for (int right = 0; right < n; right++)
        {
            current[s[right] - 'a']++;

            // Now it's time to Shrink the Window if any Char appears more than
            // it needs to be
            while (current[0] > required[0] || current[1] > required[1] ||
                   current[2] > required[2])
            {
                current[s[left] - 'a']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return n - maxLength;
    }
};
int main()
{
    return 0;
}