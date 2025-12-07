#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    size_t len = strlen(str);
    if(str[len - 1] == '\n') {
        str[len -1] = '\0';
        len--;

    }

    printf("You entered: %s\n", str);

    printf("Length of the string: %zu\n", len);


    return 0;
}
