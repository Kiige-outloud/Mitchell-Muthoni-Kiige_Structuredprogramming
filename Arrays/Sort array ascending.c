#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, temp;
    int arr[50];

    printf("Input size of the array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array: \n",n);

    for(i=0; i<n; i++){
        printf("element - %d: ",i);
        scanf("%d", &arr[i]);
    }
    //Sorting in ascending order
    for(i=0; i<n -1; i++){
        for(j=i +1; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Elements of the array in sorted ascending order are: \n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
