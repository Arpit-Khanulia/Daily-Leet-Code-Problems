// https://leetcode.com/problems/longest-consecutive-sequence/

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

#include<iostream>
#include<vector>
#include <chrono>
#include<limits.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        vector<bool> temp(100000,false);
        
        for(int i=0;i<size;i++)
            temp[nums[i]]=true;
        
        int count=0;
        int max = INT_MIN;
        
        for(int i=0;i<=100000;i++)
        {
            
            if(temp[i]==true)
                count++;
            else count =0;
            
            if (max<count)
                max=count;
            
        }
        return max;
            
    }
};


int main()
{
auto begin = chrono::high_resolution_clock::now();
//*********************************************************************************
    vector<int> array{100,4,200,1,3,2};
    Solution a;
    cout<<a.longestConsecutive(array);
   



//*********************************************************************************
auto end = chrono::high_resolution_clock::now();
auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cout<<endl<<"Time measured: "<< elapsed.count() * 1e-9;
return 0;
}