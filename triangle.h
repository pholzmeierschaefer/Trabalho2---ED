typedef struct {
    int a;
    int b;
    int c;
} trngl;

void setTriangle(trngl *t, int a, int b, int c);
int getType(trngl t);
void showTriangle(trngl t);
int getPerimeter(trngl t);
double getArea(trngl t);
int isSimilar(trngl t1, trngl t2);
