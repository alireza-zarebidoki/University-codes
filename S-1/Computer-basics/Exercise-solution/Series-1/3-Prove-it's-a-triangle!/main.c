#include <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (a+b>c && a+c>b && b+c>a)
    {
        if (a==b && a==c )
        {
            printf("Equilateral");
        }
        else if (a==b || a==c || b==c)
        {
            printf("Isosceles");
        }
        else
        {
            printf("Scalene");
        }
    }
    else
    {
        printf("Invalid");
    }
    return 0;
}
