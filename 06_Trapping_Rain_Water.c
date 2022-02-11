// https://leetcode.com/problems/trapping-rain-water/

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// 15/1/2021 streak maintned

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap(int *height, int heightSize)
{
    int *left = (int *)malloc(heightSize * sizeof(int));
    int *right = (int *)malloc(heightSize * sizeof(int));
    int ans = 0;

    left[0] = height[0];
    int k = heightSize - 2;
    right[k + 1] = height[k + 1];

    for (int i = 1; i < heightSize; i++)
    {
        left[i] = MAX(left[i - 1], height[i]);

        right[k] = MAX(right[k + 1], height[k]);
        k--;
    }

    for (int i = 0; i < heightSize; i++)
    {
        ans += MIN(left[i], right[i]) - height[i];
    }

    for (int i = 0; i < heightSize; i++)
    {
        printf(" %d ", left[i]);
    }

    printf("\n");
    for (int i = 0; i < heightSize; i++)
    {
        printf(" %d ", right[i]);
    }

    printf("\n %d ", ans);

    return ans;
}

int main()
{

    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};

    trap(arr, 8);

    return 0;
}

// leetcode

// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// #define MIN(a, b) ((a) < (b) ? (a) : (b))

// int trap(int* height, int heightSize)
// {
//     int *left=(int*)malloc(heightSize*sizeof(int));
//     int *right=(int*)malloc(heightSize*sizeof(int));
//     int ans=0;

//     left[0]=height[0];
//     int k=heightSize-2;
//     right[k+1]=height[k+1];

//     for(int i=1;i<heightSize;i++)
//     {
//         left[i]=MAX(left[i-1],height[i]);

//         right[k]=MAX(right[k+1],height[k]);
//         k--;

//     }

//     for(int i=0;i<heightSize;i++)
//     {
//         ans+=MIN(left[i],right[i] )  -  height[i];
//     }

// return ans;

// }