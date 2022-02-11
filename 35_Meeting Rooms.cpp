// https://www.lintcode.com/problem/920/

// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
// Example1

// Input: intervals = [(0,30),(5,10),(15,20)]
// Output: false
// Explanation:
// (0,30), (5,10) and (0,30),(15,20) will conflict
// Example2

// Input: intervals = [(5,8),(9,15)]
// Output: true
// Explanation:
// Two times will not conflict

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Interval
{
    public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        int j=0;
        vector<int>temp(1000);
        for(int i=0;i< intervals.size();i++)
        {
            temp[intervals[i].start] = 1;
            temp[intervals[i].end] = 2;

        }

        for(int i=0;i<1000;i++)
        {
            if(temp[i] == 1)
            j++;
            else if(temp[i] == 2)
            j--;

            if(j>1)
            return 0;
        }
        return 1;

        
    }
};

