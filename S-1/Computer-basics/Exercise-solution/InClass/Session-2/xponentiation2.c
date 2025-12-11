#include <stdio.h>

int main()
{
    int a,b,x;
    long long int y;
    int i = 1;

    printf("Enter a^b : ");
    scanf("%d^%d",&a,&b);
    x = a;
    y = a;
    if(a>=0 && a<=10 && a>=0 && a<=10)
    {
        while (i<b)
        {
            y = y*x;
            i++;
        }
        printf("a^b = %lld",y);
    }
    else
    {
        printf("Invalid value.");
    }

    return 0;
}
