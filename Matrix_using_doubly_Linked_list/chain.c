#include <stdio.h>
#include <stdlib.h> // includes malloc(), free(), realloc()
#include <string.h> // includes memcpy()

#include "chain.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// implementation
matrix *create_matrix(int num_rows, int num_cols)
{

    // allocate the memory for the matrix
    matrix *mat = (matrix *)malloc(sizeof(matrix));

    // Check if memory allocation was successful
    if (mat == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }

    mat->num_rows = num_rows;
    mat->num_cols = num_cols;

    // Allocate memory for rows of the matrix
    mat->data = (int **)malloc(sizeof(int *) * num_rows);

    // Check if memory allocation was successful
    if (mat->data == NULL)
    {
        // Handle memory allocation failure
        free(mat);
        return NULL;
    }

    // Allocate memory for each row's columns
    for (int i = 0; i < num_rows; i++)
    {
        mat->data[i] = (int *)malloc(sizeof(int) * num_cols);
    }

    // Initialize matrix elements to 0
    int *p;
    for (p = &mat->data[0][0]; p <= &mat->data[num_rows - 1][num_cols - 1]; p++)
    {

        *p = 0;
    }

    return mat;
}
int calculatePower(int num, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= num;
    }
    return result;
}

void add_row(matrix *mat, int *row)
{
    mat->data = realloc(mat->data, (sizeof(int *) * (mat->num_rows + 1)));
    mat->data[mat->num_rows] = row;
    mat->num_rows += 1;
}

void add_col(matrix *mat, int *col)
{
    for (int i = 0; i < mat->num_rows; i++)
    {
        mat->data[i] = (int *)realloc(mat->data[i], sizeof(int) * (mat->num_cols + 1));
        if (mat->data[i] == NULL)
        {
            // Handle memory allocation failure
            return;
        }

        mat->data[i][mat->num_cols] = col[i]; // Copy the value from the col array
    }
    mat->num_cols += 1;
}

void increment(matrix *mat, int num)
{
    int *p;
    for (p = &mat->data[0][0]; p <= &mat->data[mat->num_rows - 1][mat->num_cols - 1]; p++)
    {

        *p += num;
    }
}

void scalar_multiply(matrix *mat, int num)
{
    int *p;
    for (p = &mat->data[0][0]; p <= &mat->data[mat->num_rows - 1][mat->num_cols - 1]; p++)
    {

        *p *= num;
    }
}

void scalar_divide(matrix *mat, int num)
{
    if (num != 0)
    {
        int *p;
        for (p = &mat->data[0][0]; p <= &mat->data[mat->num_rows - 1][mat->num_cols - 1]; p++)
        {

            *p /= num;
        }
    }
    else
    {
        printf("Error: Cannot divide by zero");
    }
}

void scalar_power(matrix *mat, int num)
{
    int *p;
    for (p = &mat->data[0][0]; p <= &mat->data[mat->num_rows - 1][mat->num_cols - 1]; p++)
    {

        *p = calculatePower(*p, num);
    }
}
//
//void delete_matrix(matrix *mat)
//{
//    int *p;
//    for (p = &mat->data[0][0]; p <= &mat->data[mat->num_rows - 1][mat->num_cols - 1]; p++)
//    {
//
//        free(p);
//    }
//}

/*
    DO NOT MODIFY BELOW
*/
// print out matrix in row-major order
// elements in the same row are space-separated
// each row starts in a new line
void print_matrix(matrix *mat)
{
    int row_idx, col_idx;
    for (row_idx = 0; row_idx < mat->num_rows; ++row_idx)
    {
        for (col_idx = 0; col_idx < mat->num_cols; ++col_idx)
        {
            if (col_idx == mat->num_cols - 1)
            {
                printf("%d\n", mat->data[row_idx][col_idx]);
            }
            else
            {
                printf("%d ", mat->data[row_idx][col_idx]);
            }
        }
    }
}

// Add the rest of the functions needed for the chain below
int main()
{

    matrix *mat = create_matrix(3, 3);
     increment(mat, 1);
    // add_row(mat, (int[]){1, 2, 3});
    add_col(mat, (int[]){1, 2, 3});
    //scalar_multiply(mat, 4);
    //  scalar_divide(mat, 2);
    // scalar_power(mat, 2);
//      delete_matrix(mat);
    print_matrix(mat);

    return 0;
}