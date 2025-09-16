#include <stdio.h>
#include <math.h>
#include "triangle.h"

// atribui valores
void setTriangle(trngl *t, int a, int b, int c) {
    t->a = a;
    t->b = b;
    t->c = c;
}

// checa se lados formam triângulo válido
static int isTriangle(trngl t) {
    return (t.a + t.b > t.c) &&
           (t.a + t.c > t.b) &&
           (t.b + t.c > t.a);
}

// retorna tipo: 0 inválido, 1 equilátero, 2 isósceles, 3 escaleno
int getType(trngl t) {
    if (!isTriangle(t))
        return 0;
    if (t.a == t.b && t.b == t.c)
        return 1;
    if (t.a == t.b || t.b == t.c || t.a == t.c)
        return 2;
    return 3;
}

// mostra lados
void showTriangle(trngl t) {
    printf("AB: %d, BC: %d, CA: %d\n", t.a, t.b, t.c);
}

// retorna perímetro
int getPerimeter(trngl t) {
    if (!isTriangle(t))
        return 0;
    return t.a + t.b + t.c;
}

// retorna área (Heron)
double getArea(trngl t) {
    if (!isTriangle(t))
        return 0.0;
    double p = (t.a + t.b + t.c) / 2.0;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

// retorna 1 se são similares, senão 0
int isSimilar(trngl t1, trngl t2) {
    if (!isTriangle(t1) || !isTriangle(t2))
        return 0;

    // ordenar lados para comparar
    int s1[3] = {t1.a, t1.b, t1.c};
    int s2[3] = {t2.a, t2.b, t2.c};

    // bubble sort simples (3 elementos)
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (s1[i] > s1[j]) { int tmp = s1[i]; s1[i] = s1[j]; s1[j] = tmp; }
            if (s2[i] > s2[j]) { int tmp = s2[i]; s2[i] = s2[j]; s2[j] = tmp; }
        }
    }

    // proporção entre lados deve ser a mesma
    double r1 = (double)s1[0] / s2[0];
    double r2 = (double)s1[1] / s2[1];
    double r3 = (double)s1[2] / s2[2];

    // compara com tolerância para evitar erro de ponto flutuante
    const double EPS = 1e-6;
    return (fabs(r1 - r2) < EPS) && (fabs(r2 - r3) < EPS);
}
