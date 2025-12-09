#include <stdio.h>

int main()
{
    double a, b, c, d;
    double x, y;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    if (c == 0.0 && d == 0.0) {
        printf("Division by zero is not allowed\n");
        return 0;
    }

    x = ((a*c) + (b*d)) / ((c*c) + (d*d));
    y = ((b*c) - (a*d)) / ((c*c) + (d*d));

    if (x > -0.000001 && x < 0.000001) x = 0.0;
    if (y > -0.000001 && y < 0.000001) y = 0.0;

    if (y >= 0)
        printf("Quotient = %.2lf + %.2lfi\n", x, y);
    else
        printf("Quotient = %.2lf - %.2lfi\n", x, -y);

    return 0;
}
