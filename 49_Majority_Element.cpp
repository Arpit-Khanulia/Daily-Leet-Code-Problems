// https://leetcode.com/problems/majority-element/
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include<iostream>
#include<vector>
#include <chrono>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size = nums.size();
        int n = size/2,count =1;
        if(size==1)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<size-1 ;i++)
        {
            if(nums[i+1] == nums[i])
                count++;
            else count =1;
            
            if(count > n)
                return nums[i];
        }
        
        return 0;
    }
};

int main()
{
auto begin = chrono::high_resolution_clock::now();
//*********************************************************************************

   
vector<int> array{2,2,1,1,1,2,2};
Solution a;
cout<<a.majorityElement(array);


//*********************************************************************************
auto end = chrono::high_resolution_clock::now();
auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
cout<<endl<<"Time measured: "<< elapsed.count() * 1e-9;
return 0;
}