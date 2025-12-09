#include <stdio.h> 

int main()
{
    double a,b,c,d;
    double x,y;
    scanf("%lf %lf", &a, &b);
    scanf("%lf %lf", &c, &d);
    x = (a*c)-(b*d);
    y = (a*d)+(b*c);

    if (y >= 0)
        printf("%.2lf + %.2lfi",x,y);
    else
        printf("%.2lf - %.2lfi",x,-y);

    return 0;
}
