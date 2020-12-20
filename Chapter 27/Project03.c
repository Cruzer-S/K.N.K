#include <stdio.h>
#include <math.h>
#include <complex.h>

struct rs {
    double r;
    double s;
};
double complex ptoc(struct rs val)
{          
    return (val.r * cos(val.s))
         + (val.r * sin(val.s)) * I;
}

struct rs ctop(double complex p)
{
    double r = creal(p), 
           i = cimag(p);
           
    return (struct rs) {
        .r = sqrt((r * r) + (i * i)),
        .s = atan(i / r)
    };
}

void show_complex(double complex val)
{
    if (cimag(val) != 0.0) {
        printf("%g %c %gi", creal(val), "+-"[cimag(val) < 0], fabs(cimag(val)));
    } else {
        printf("%g", creal(val));
    }
}

int main(void)
{
    struct rs val;
    double complex value;

    scanf("%lf %lf", &val.s, &val.r);
    show_complex(ptoc(val)); putchar('\n');

    val = ctop(ptoc(val));
    printf("%lf %lf \n", val.s, val.r);

    return 0;
}