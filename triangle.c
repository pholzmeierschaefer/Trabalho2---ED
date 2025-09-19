#include <stdio.h>
#include <math.h>
#include "triangle.h"

void setTriangle(trngl *t, int a, int b, int c)
{
    t->a = a;
    t->b = b;
    t->c = c;
}
//
int getType(trngl t)
{
    if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a)
    {
        if (t.a == t.b && t.b == t.c)
        {
            return 1;
        }
        if (t.a == t.b || t.b == t.c || t.a == t.c)
        {
            return 2;
        }
        else
            return 3;
    }
    else
    {
        return 0;
    }
}
//
void showTriangle(trngl t)
{
    printf("AB = %d, BC = %d, CA = %d", t.a, t.b, t.c);
}
//
int getPerimeter(trngl t)
{
    return t.a + t.b + t.c;
}
//
double getArea(trngl t)
{
     double s = (double)(t.a + t.b + t.c) / 2;
     if (s <= t.a || s <= t.b || s <= t.c) 
     {
        return 0;
    }
    double area = sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
    return area;
}
//
int isSimilar(trngl t1, trngl t2)
{
    double eps = 1e-6;

    double r1 = t1.a / t2.a;
    double r2 = t1.b / t2.b;
    double r3 = t1.c / t2.c;

    double cos1_1 = (pow(t1.a, 2) + pow(t1.b, 2) - pow(t1.c, 2)) / (2 * t1.a * t1.b);
    double cos1_2 = (pow(t2.a, 2) + pow(t2.b, 2) - pow(t2.c, 2)) / (2 * t2.a * t2.b);

    double cos2_1 = (pow(t1.b, 2) + pow(t1.c, 2) - pow(t1.a, 2)) / (2 * t1.b * t1.c);
    double cos2_2 = (pow(t2.b, 2) + pow(t2.c, 2) - pow(t2.a, 2)) / (2 * t2.b * t2.c);

    double cos3_1 = (pow(t1.c, 2) + pow(t1.a, 2) - pow(t1.b, 2)) / (2 * t1.c * t1.a);
    double cos3_2 = (pow(t2.c, 2) + pow(t2.a, 2) - pow(t2.b, 2)) / (2 * t2.c * t2.a);

    if ((fabs(cos1_1 - cos1_2) < eps && fabs(cos2_1 - cos2_2) < eps && fabs(cos3_1 - cos3_2) < eps) && (fabs(r1 - r2) < eps && fabs(r2 - r3) < eps))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
