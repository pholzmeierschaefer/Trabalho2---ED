#include <stdio.h>
#include "triangle.h"
//
int main()
{
    trngl t1, t2, t3, t4;
    char *type[20] = {"Not Triangle", "Equilateral", "Isoceles", "Scalene"};
    char *YesNo[4] = {"No", "Yes"};
    setTriangle(&t1, 4, 4, 4);
    setTriangle(&t2, 4, 4, 7);
    setTriangle(&t3, 4, 5, 6);
    setTriangle(&t4, 20, 15, 5);
    printf("t1: %s\n", type[getType(t1)]);
    printf("t2: %s\n", type[getType(t2)]);
    printf("t3: %s\n", type[getType(t3)]);
    printf("t4: %s\n", type[getType(t4)]);
    showTriangle(t1);
    printf("\n");
    showTriangle(t3);
    printf("\n");
    //
    printf("Perimeter t1: %d\n", getPerimeter(t1));
    printf("Perimeter t2: %d\n", getPerimeter(t2));
    printf("Perimeter t3: %d\n", getPerimeter(t3));
    ///
    printf("Area t1: %f\n", getArea(t1));
    printf("Area t2: %f\n", getArea(t2));
    printf("Area t3: %f\n", getArea(t3));
    ///
    printf("Similarity (t1,t2): %s\n", YesNo[isSimilar(t1, t2)]);
    printf("Similarity (t2,t3): %s\n", YesNo[isSimilar(t2, t3)]);
    printf("Similarity (t1,t3): %s\n", YesNo[isSimilar(t1, t3)]);

    return 0;
}