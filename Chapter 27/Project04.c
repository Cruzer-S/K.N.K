#include <stdio.h>
#include <math.h>
#include <complex.h>

#define PI (3.141592)

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
    double complex result;
    int n;

    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        result = cexp((2 * PI * I * k) / n);
        show_complex(result); putchar('\n');
    }
    
    return 0;
}