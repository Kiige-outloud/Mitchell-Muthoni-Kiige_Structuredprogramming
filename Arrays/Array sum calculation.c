#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int arr[50];
    int sum = 0;

    printf("Input number of elements to be stored in array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array: \n", n);

    for(i=0; i<n; i++){
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    printf("Sum of all elements in the array is: %d\n", sum);

    return 0;
}
