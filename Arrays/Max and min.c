#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, i;
   int arr[50];
   int max, min;

   printf("Input number of elements to be stored in the array: ");
   scanf("%d", &n);

   printf("Input %d elements in the array: \n", n);

   for(i=0; i<n; i++){
    printf("element - %d: ", i);
    scanf("%d", &arr[i]);
   }
   //Assume first element is both max and min
   max = arr[0];
   min = arr[0];

   //Compare with the rest of the elements
   for(i=1; i<n; i++){
    if(arr[i] > max){
        max = arr[i];
    }
    if(arr[i] < min){
        min = arr[i];
    }
   }
   printf("Maximum element is : %d\n", max);
   printf("Minimum element is : %d\n", min);
    return 0;
}
