// https://leetcode.com/problems/rotate-image/

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

//  matrix    transpose    rotate 90 degree
//  [1,2,3]   [1,4,7]       [7,4,1]
//  [4,5,6]   [2,5,8]       [8,5,2]
//  [7,8,9]   [3,6,9]       [9,6,3]

// example 2

// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// transverse the matrix than reverse every row.

// 17/1/2022 streak maintained

#include <stdio.h>
#include <stdlib.h>

void print(int (*matrix)[3], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++)
        {
            if ((j) % 3 == 0)
                printf("\n");
            printf(" %d ", matrix[i][j]);
        }
}

void reverse(int (*matrix)[3], int matrixsize)
{
    int temp = 0;
    int j = 0;
    int k = matrixsize - 1;
    for (int i = 0; i < matrixsize; i++)
    {
        while (j < k)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
            j++;
            k--;
        }
        k = matrixsize - 1;
        j = 0;
    }

    print(matrix, matrixsize);
}

void transpose(int (*matrix)[3], int matrixSize)
{
    int temp;

    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < i; j++)
        {

            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

    print(matrix, matrixSize);
}

void rotate(int (*matrix)[3], int matrixSize)
{

    printf("\n\ntranspose\n ");
    transpose(matrix, matrixSize);
    printf("\n\nreverse\n ");
    reverse(matrix, matrixSize);
}

int main()
{
    int matrix[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // int matrix[4][4] = {5,1,9,11,2,4,8,10,13,3,6,7,15,14,12,16};
    print(matrix, 3);
    rotate(matrix, 3);

    return 0;
}