#include <stdio.h>
#include <math.h>
#include <complex.h>

struct rs {
    double r;
    double s;
};

struct rs ctop(double complex p)
{
    double r = creal(p), 
           i = cimag(p);
           
    return (struct rs) {
        .r = sqrt(r * r + i * i),
        .s = atan(i / r)
    };
}

int main(void)
{
    struct rs result;
    double a, b;

    scanf("%lf %lf", &a, &b);
    result = ctop(a + b * I);
    printf("radian: %g\tr: %g \n",
            result.s, result.r);

    return 0;
}