// https://leetcode.com/problems/container-with-most-water/

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// 15/1/2022 streak mantained

#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int height[], int heightSize)
{
    int ans = 0;

    int i = 0;
    int j = heightSize - 1;
    while (i < j)
    {
        printf(" %d and %d * %d \n ",ans,MIN(height[i],height[j]),j-i);
        ans = MAX(ans, MIN(height[i],height[j])  *  abs(j-i));
        printf(" %d  \n ",ans);

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    printf(" final ans = %d ",ans);
    return ans;
}

int main()
{

    // int height[] = {1,8,6,2,5,4,8,3,7};

    
 int height[] ={2,3,4,5,18,17,6};


    maxArea(height,7);

    return 0;
}

// naive approach O(n2)

// int maxArea(int* height, int heightSize){
//     int max= INT_MIN;
//     for(int i=0;i<heightSize;i++)
//     {
//         for(int j=i+1;j<heightSize ;j++)
//         {
//             if(height[i]<=height[j] &&  max<(height[i]* (j- i)))
//             {
//                max=height[i]* (j- i);

//             }
//             else if(height[i]>height[j]  &&  max<(height[j]* (j- i)) )
//             {
//                max=height[j]* (j- i);

//             }
//         }
//     }
//     return max;
// }



// leetcode funtion  O(n)

// #define MAX(a, b) ((a) > (b) ? (a) : (b))
// #define MIN(a, b) ((a) < (b) ? (a) : (b))

// int maxArea(int *height, int heightSize)
// {
//     int ans = 0;
//     int i = 0;
//     int j = heightSize - 1;
//     while (i < j)
//     {
//         ans = MAX(ans, MIN(height[i],height[j])  *  (j-i));
//         if (height[i] < height[j])
//             i++;
//         else
//             j--;
//     }
//     return ans;
// }
