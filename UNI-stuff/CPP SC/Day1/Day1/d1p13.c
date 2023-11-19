/* when we want to perform matrix multiplication. 
For example, if we have two matrices A and B of size m x n and n x p respectively, 
and we want to compute their product C of size m x p. We can use this formula:

C[i][j] = sum(A[i][k] * B[k][j]) for k = 0 to n - 1 */

#include <stdio.h>

int main()
{
    int m = 2, n = 3, p = 2; // dimensions of the matrices
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}}; // first matrix
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}}; // second matrix
    int C[2][2]; // result matrix
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            C[i][j] = 0; // initialize the element to zero
            for (k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j]; // compute the element using the formula
            }
        }
    }
    // print the result matrix
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
