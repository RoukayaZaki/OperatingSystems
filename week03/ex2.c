#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{

    double x, y;

} Point;

double distance(Point A, Point B)
{
    double result = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    return sqrt(result);
}

double area(Point A, Point B, Point C)
{

    return abs((A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y)) / 2.0;
}

int main(void)
{

    Point A = {2.5, 6};
    Point B = {1, 2.2};
    Point C = {10, 6};

    float f = distance(A, B);
    printf("A -- B distance is %lf\n", f);

    float a = area(A, B, C);
    printf("Area of triangle ABC is %lf\n", a);

    return 0;
}