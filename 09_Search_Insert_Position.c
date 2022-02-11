// https://leetcode.com/problems/search-insert-position/

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1



// 16/01/2022 streak maintained
// redo with better code

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int i = 0, j = numsSize;
    if(target <nums[0]) return 0;

    while (1)
    {
        int k = (i + j) / 2;

        if (nums[k] == target)
        {
            printf("  %d  ", k);
            return k;
        }
        else if (target < nums[k])
            j = k;
        else if (target > nums[k])
            i = k;

        if ((i == j) || ((j - i == 1) && (nums[i] != target)))
        {
           
            printf("  %d  ", j);
            return j;
        }
    }
}
int main()
{

    int nums[] = {2,5};
    int target = 1;
    searchInsert(nums, 2, target);

    return 0;
}