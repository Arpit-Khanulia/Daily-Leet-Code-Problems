// https://leetcode.com/problems/minimum-time-difference/

// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".

#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {

        vector<int> temp(1441);

        for (int i = 0; i < timePoints.size(); i++)
            temp[stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 4))]++;

        int j;
        for (j = 0; j <= 1440; j++)
        {
            if (temp[j] > 1)
                return 0;

            if (temp[j] == 1)
                break;
        }

        int min = INT_MAX;
        int prev = j, first = j, curr = 0;
        for (int i = j + 1; i <= 1440; i++)
        {
            if (temp[i] > 1)
                return 0;
            if (temp[i] == 1)
            {
                curr = i;
                if (min > (curr - prev))
                    min = curr - prev;

                prev = curr;
            }
        }
        cout << curr << endl;
        if (min > (first + 1440 - curr))
            min = first + 1440 - curr;

        return min;
    }
};

int main()
{
    auto begin = chrono::high_resolution_clock::now();
    //*********************************************************************************

    vector<string> s{"00:00", "23:59", "00:00"};

    Solution a;
    cout << a.findMinDifference(s);

    //*********************************************************************************
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << endl
         << "Time measured: " << elapsed.count() * 1e-9;
    return 0;
}

// leetcode method 1 O(nlogn)time O(N)_SPACE

// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {

//         int size = timePoints.size();
//         vector<int>integer(size);
//         sort(timePoints.begin(),timePoints.end());
//         int min = INT_MAX;

//         for(int j=0 ; j<size;j++)
//             integer[j]= stoi(timePoints[j].substr(0,2)) * 60 + stoi(timePoints[j].substr(3,4));

//         for(int i =0; i<size-1;i++)
//         {
//             if(min > integer[i+1] - integer[i])
//                 min = integer[i+1] - integer[i];
//         }

//         if(min > ((integer[0] + 1440) - integer[size-1] )  )
//             min = ((integer[0] + 1440) - integer[size-1] );

//         return min;

//     }
// };