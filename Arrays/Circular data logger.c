#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
    int buffer[100];
    int size;
    int count = 0;
    int value;
    int i;

    // Ask for buffer size
    printf("Enter buffer size: ");
    scanf("%d", &size);

    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);

        // Insert using circular logic
        buffer[count % size] = value;
        count++;

        // Display buffer contents
        printf("Buffer contents: ");

        if (count < size) {
            // Buffer not full yet
            for (i = 0; i < count; i++) {
                printf("%d ", buffer[i]);
            }
        } else {
            // Buffer full → print from oldest to newest
            for (i = 0; i < size; i++) {
                printf("%d ", buffer[(count + i) % size]);
            }
        }
        printf("\n");

        // Continue?
        printf("Continue? (1 = yes, 0 = no): ");
        scanf("%d", &value);

        if (value == 0)
            break;
    }

    return 0;
}



