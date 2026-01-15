#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, i, pos, value;
   int arr[50];

   printf("Input size of array: ");
   scanf("%d", &n);

   printf("Input %d elements in the array: \n", n);

   for(i=0; i<n; i++){
    printf("element - %d: ", i);
    scanf("%d", &arr[i]);
   }

   printf("Input the value to be inserted: ");
   scanf("%d", &value);

   printf("Input the position where the value should be inserted(1 to %d): ", n+1);
   scanf("%d", &pos);

   for(i=n; i >= pos; i--){
    arr[i] = arr[i - 1];
   }

   arr[pos - 1] = value;
   n++;

   printf("After inserting the element, the new array is: \n");
   for(i=0; i<n; i++){
    printf("%d ", arr[i]);
   }

    return 0;
}
