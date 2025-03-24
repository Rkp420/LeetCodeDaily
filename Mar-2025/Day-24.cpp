#include <iostream>
using namespace std;

// https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        if (meetings.empty())
            return days; // If no meetings, all days are free

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int ans = 0;
        int lastMeetingEnd = 0;

        for (auto &meeting : meetings)
        {
            int start = meeting[0];
            int end = meeting[1];

            if (start > lastMeetingEnd + 1)
            {
                ans += (start - lastMeetingEnd - 1); // Count free days between meetings
            }

            lastMeetingEnd = max(lastMeetingEnd, end); // Update the last meeting's end time
        }

        // Count free days after the last meeting
        if (lastMeetingEnd < days)
        {
            ans += (days - lastMeetingEnd);
        }

        return ans;
    }
};

int main()
{
    return 0;
}