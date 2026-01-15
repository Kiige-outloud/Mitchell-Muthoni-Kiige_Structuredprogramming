#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    int arr[10][10];
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the array: \n");

    for(i=0; i< rows; i++){
        for(j=0; j< cols; j++){
            printf("element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nThe 2D array is: \n");
    for(i=0; i< rows; i++){
        for(j=0; j< cols; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
