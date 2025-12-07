#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI = 3.141592653589793;
    int radius;
    double surface_area;

    printf("Enter the radius of the sphere:");
    scanf("%d", &radius);

    surface_area = 4 * PI * radius * radius;

    printf("Surface area = %.4lf\n", surface_area);

    return 0;
}
