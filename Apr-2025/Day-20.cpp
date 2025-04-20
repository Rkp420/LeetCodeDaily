#include <iostream>
using namespace std;

// https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> rabbitCount;
        int totalRabbits = 0;

        for (int n : answers)
        {
            // If the group size (n + 1) is not in the map or is already fully used
            if (rabbitCount[n + 1] == 0)
            {
                // Add a new group of n + 1 rabbits
                totalRabbits += n + 1;
                rabbitCount[n + 1] = n; // n more rabbits can use this group
            }
            else
            {
                // Reduce the count for this group
                rabbitCount[n + 1]--;
                // Remove the entry if no more rabbits can use this group
                if (rabbitCount[n + 1] == 0)
                {
                    rabbitCount.erase(n + 1);
                }
            }
        }

        return totalRabbits;
    }
};

int main()
{
    return 0;
}