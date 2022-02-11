// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

// There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.

// A city's skyline is the the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.

// We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.

// Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.

// Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
// Output: 35
// Explanation: The building heights are shown in the center of the above image.
// The skylines when viewed from each cardinal direction are drawn in red.
// The grid after increasing the height of buildings without affecting skylines is:
// gridNew = [ [8, 4, 8, 7],
//             [7, 4, 7, 7],
//             [9, 4, 8, 7],
//             [3, 3, 3, 3] ]

#include <stdio.h>
#include <stdlib.h>

int max(int i, int j, int (*grid)[4], int gridSize)
{
    int max1 = 0;
    int max2 = 0;
    for (int k = 0; k < gridSize; k++)
    {
        if (max1 < grid[i][k])
            max1 = grid[i][k];
    }
    for (int k = 0; k < gridSize; k++)
    {
        if (max2 < grid[k][j])
            max2 = grid[k][j];
    }

    printf("max row = %d and max column = %d \n", max1, max2);

    if (max1 <= max2)
        return max1;
    else
        return max2;
}

int maxIncreaseKeepingSkyline(int (*grid)[4], int gridSize)
{

    int count = 0, m = 0;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            m = max(i, j, grid, gridSize);

            count = count + abs(grid[i][j] - m);

            grid[i][j] = m;
        }
    }

    printf(" %d ", count);
    return count;
}

int main()
{
    int grid[4][4] = {3, 0, 8, 4, 2, 4, 5, 7, 9, 2, 6, 3, 0, 3, 1, 0};
    maxIncreaseKeepingSkyline(grid, 4);
}


// leetcode function


// int max(int i,int j,int **grid,int gridSize)
// {
//     int max1 =0;
//     int max2 =0;
//  for(int k=0;k<gridSize;k++)
//     {
//         if(max1<grid[i][k])
//         max1 =  grid[i][k];

//     }
//     for(int k=0;k<gridSize;k++)
//     {
//         if( max2 < grid[k][j])
//         max2=grid[k][j];

//     }

//     if(max1<=max2)
//     return max1;
//     else return max2;
// }


// int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize)
// {

//     int count=0,m=0;

//     for(int i=0; i<gridSize;i++)
//     {
//         for(int j=0;j<gridSize;j++)
//         {
//            m= max(i,j,grid,gridSize);

//            count = count +  abs(grid[i][j]  - m );

//            grid[i][j]=m;

//         }
//     }

//     return count;

// }
