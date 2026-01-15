#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n, i;
 int arr[50];

 printf("Input the number of elements to store in the array: \n");
 scanf("%d", &n);

 printf("Input %d elements in the array: \n", n);

    for(i=0; i<n; i++){
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nThe values stored into the array are: \n");
        for(i=0; i<n ; i++){
            printf("%d", arr[i]);
        }
        printf("\nThe values stored into the array in reverse are: \n");
            for(i=n-1; i>=0; i--){
                printf("%d", arr[i]);
            }

    return 0;
}
