#include <iostream>
using namespace std;


// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/?envType=daily-question&envId=2025-06-20

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char it : s)
        {
            switch (it)
            {
            case 'N':
                north++;
                break;
            case 'S':
                south++;
                break;
            case 'E':
                east++;
                break;
            case 'W':
                west++;
                break;
            }
            int times1 =
                min({north, south, k}); // modification times for N and S
            int times2 = min(
                {east, west, k - times1}); // modification times for E and W
            ans = max(ans,
                      count(north, south, times1) + count(east, west, times2));
        }
        return ans;
    }

    int count(int drt1, int drt2, int times)
    {
        return abs(drt1 - drt2) + times * 2;
    } // Calculate modified Manhattan distance
};

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};

int main()
{
    return 0;
}